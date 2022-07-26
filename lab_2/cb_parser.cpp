#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include "nlohmann/json.hpp"
#include <boost/optional.hpp>
#include <boost/beast.hpp>
#include <chrono>
#include <thread>
#include <algorithm>

#define GetNewData 35
#define Exit 36
#define GetButtom 37
#define SaveNotes 38

int numberOfWindow = -1;
bool flagRekursion = 1;

HWND results;

int counter = 0;

nlohmann::json j{};

std::string result;

static int GetResponseToTheRequest()
{
	boost::asio::io_context ioContext;
	boost::asio::ip::tcp::resolver resolver(ioContext);
	boost::asio::ip::tcp::socket socket(ioContext);
	boost::asio::connect(socket, resolver.resolve("www.cbr-xml-daily.ru", "80"));
	boost::beast::http::request<boost::beast::http::string_body> Request(boost::beast::http::verb::get, "/daily_json.js", 11);
	Request.set(boost::beast::http::field::host, "www.cbr-xml-daily.ru");
	Request.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);
	boost::beast::http::write(socket, Request);
	{
		boost::beast::flat_buffer buffer;
		boost::beast::http::response<boost::beast::http::dynamic_body> resultOfResponse;
		boost::beast::http::read(socket, buffer, resultOfResponse);
		result = boost::beast::buffers_to_string(resultOfResponse.body().data());

		j = nlohmann::json::parse(result);
	}
	socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
	return 0;
}

struct Data
{
	Data()
	{
		this->Nominal = 0;
		this->sum = 0;
		this->Previous = 0;
		this->Value = 0;
	}

	std::string ID;
	std::string NumCode;
	std::string CharCode;
	int Nominal;
	double Value;
	double Previous;
	std::vector<double> values;
	double sum;
};

struct AllData
{
	std::vector<Data> allD;
};

AllData MyData;

void parseJSON()
{
	try
	{
		std::cout << "Date === " << j["Date"] << std::endl;
		std::cout << "PreviousDate === " << j["PreviousDate"] << std::endl;
		std::cout << "PreviousURL === " << j["PreviousURL"] << std::endl;
		std::cout << "Timestamp === " << j["Timestamp"] << std::endl;
		nlohmann::json j2;
		j2 = j["Valute"];
		nlohmann::json::iterator it = j2.begin();
		for (int i = 0; i < 34; i++)
		{
			MyData.allD[i].ID = (*it)["ID"];
			MyData.allD[i].Nominal = (*it)["Nominal"];
			MyData.allD[i].CharCode = (*it)["CharCode"];
			MyData.allD[i].NumCode = (*it)["NumCode"];
			MyData.allD[i].Previous = (*it)["Previous"];
			MyData.allD[i].Value = (*it)["Value"];
			MyData.allD[i].values.push_back((*it)["Value"]);
			++it;
			std::cout << MyData.allD[i].CharCode << " === " << MyData.allD[i].Value << std::endl;
			MyData.allD[i].sum += MyData.allD[i].Value;
		}
	}
	catch (const std::exception&)
	{
		parseJSON();
	}
}

void createWidgets(HWND hWindow);

LRESULT CALLBACK management(HWND hWindow, UINT message, WPARAM wparametr, LPARAM lparametr);

void TimeReqwests(HWND hWindow)
{
	while (flagRekursion)
	{
		try
		{
		label:
			GetResponseToTheRequest();
		}
		catch (const std::exception & except)
		{
			goto label;
		}

		counter++;

		parseJSON();

		std::this_thread::sleep_for(std::chrono::milliseconds(10000));
		createWidgets(hWindow);
	}
}

void Save(LPCSTR path);
void printValuesAtTehEnd(HWND hWindow);
void printResults(HWND hWindow);
void createMenu(HWND hWindow);
void createWidgets(HWND hWindow);
LRESULT CALLBACK management(HWND hWindow, UINT message, WPARAM wparametr, LPARAM lparametr);
WNDCLASS newWindow(HBRUSH backGroundColor, HCURSOR cursor, HINSTANCE hInstance, HICON icon, LPCWSTR name, WNDPROC management);

void task1(std::string msg)
{
	std::cout << "task1 says: " << msg;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevelationInstance, LPSTR arguments, int ncmdshow)
{
	for (int i = 0; i < 34; i++)
	{
		Data New;
		MyData.allD.push_back(New);
	}

	WNDCLASS window = newWindow((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_HAND), hInstance, LoadIcon(NULL, IDI_QUESTION), L"Window", management);

	if (!RegisterClassW(&window))
	{
		return -1;
	}

	MSG message = { 0 };

	CreateWindow(L"Window", L"CB RF PARSER", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 1000, 750, NULL, NULL, NULL, NULL);
	label:
	try
	{
		while (GetMessage(&message, NULL, NULL, NULL))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}
	catch (const std::exception&)
	{
		goto label;
	}
}

WNDCLASS newWindow(HBRUSH backGroundColor, HCURSOR cursor, HINSTANCE hInstance, HICON icon, LPCWSTR name, WNDPROC management)
{
	WNDCLASS window = { 0 };

	window.hbrBackground = backGroundColor;
	window.hCursor = cursor;
	window.hInstance = hInstance;
	window.lpszClassName = name;
	window.lpfnWndProc = management;
	window.hIcon = icon;

	return window;
}

const char * doubleToLPCSTR(float x);

LRESULT CALLBACK management(HWND hWindow, UINT message, WPARAM wparametr, LPARAM lparametr)
{
	if (message == GetNewData) 
	{
		createWidgets(hWindow);
	}
	switch (message)
	{
	case WM_COMMAND:
		switch (wparametr)
		{
		case GetAUDGrafic:
			break;
		case Exit:
			PostQuitMessage(0);
			break;

		case GetButtom:
			flagRekursion = 0;
			for (int i = 0; i < 34; i++)
			{
				SetWindowTextA(mas[i], "");
			}
			MessageBoxA(hWindow, "data acquisition stopped", "message", MB_OK);
			printValuesAtTehEnd(hWindow);
			break;

		case SaveNotes:
			Save("C:\\Users\\user\\source\\repos\\cb_parser\\cb_parser\\My_notes.txt");
			MessageBoxA(hWindow, "your notes saved", "message", MB_OK);
			break;

		default:
			break;
		}
		break;
	case WM_CREATE:
		createMenu(hWindow);
		createWidgets(hWindow);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWindow, message, wparametr, lparametr);
	}
}


void createMenu(HWND hWindow)
{
	HMENU mainMenu = CreateMenu();
	HMENU graficMenu = CreateMenu();
	HMENU graficsMenus = CreateMenu();

	AppendMenu(graficMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(graficMenu, MF_STRING, Exit, L"Exit");

	AppendMenu(mainMenu, MF_POPUP, (UINT_PTR)graficMenu, L"menu");

	SetMenu(hWindow, mainMenu);

	CreateWindowA("button", "get results", WS_VISIBLE | WS_CHILD | ES_CENTER, 145, 5, 120, 30, hWindow, (HMENU)GetButtom, NULL, NULL);

	CreateWindowA("button", "Save my notes", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 545, 120, 30, hWindow, (HMENU)SaveNotes, NULL, NULL);

	CreateWindowA("static", "After you stop updating the data, you will be able to make notes about the received data, which after clicking the button will be saved to a file.", WS_VISIBLE | WS_CHILD | ES_CENTER, 155, 545, 500, 30, hWindow, NULL, NULL, NULL);

	MY_NOTES = CreateWindowA("edit", "you can write here", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 5, 580, 300, 90, hWindow, NULL, NULL, NULL);
}

const char * doubleToLPCSTR(float x) 
{
	const int size = 9;
	char *charMassTemp = new char[size];
	std::string str;
	std::stringstream strstr;
	strstr << x;
	str = strstr.str();
	const char * temp = str.c_str();

	for (int i = 0; i < size; i++) 
	{
		charMassTemp[i] = temp[i];
	}
	return charMassTemp;
}

void printFinishResults(HWND hWindow)
{
	CreateWindowA("static", " %", WS_VISIBLE | WS_CHILD, 375, 5, 29, 15, hWindow, NULL, NULL, NULL);
}

void createWidgets(HWND hWindow)
{
	if (counter == 0)
	{
		std::thread t1(TimeReqwests, hWindow);
		t1.detach();
		Sleep(1000);
	}
	try
	{
		char * allresult = new char[473];
		int allresultCnt = 0;
		char sleshN[3];

		for (int i = 1; i <= 34; i++)
		{

			if (counter == 1)
			{
				std::stringstream tempstr;
				tempstr << MyData.allD[i - 1].CharCode;
				std::string str;
				str = tempstr.str();
				const char * temp = str.c_str();
				char * charMassTemp = new char[4];
				for (int j = 0; j < 3; j++)
				{
					charMassTemp[j] = temp[j];
					allresult[allresultCnt] = charMassTemp[j];
					allresultCnt = allresultCnt + 1;
				}
				CreateWindowA("static", charMassTemp, WS_VISIBLE | WS_CHILD, 5, 15 * i + 15, 29, 15, hWindow, NULL, NULL, NULL);
				mas[i - 1] = CreateWindowA("static", doubleToLPCSTR(MyData.allD[i - 1].Value), WS_VISIBLE | WS_CHILD, 70, 15 * i + 15, 60, 15, hWindow, NULL, NULL, NULL);
			}
			else
			{
				std::vector<double>::iterator Iterator;
				Iterator = MyData.allD[i - 1].values.end();
				double firstD = *Iterator;
				Iterator--;
				double secondD = *Iterator;
				if (secondD == firstD)
				{
					SetWindowTextA(mas[i - 1], doubleToLPCSTR(MyData.allD[i - 1].Value));
				}
			}
		}
		CreateWindowA("static", "percentages", WS_VISIBLE | WS_CHILD, 305, 7, 100, 15, hWindow, NULL, NULL, NULL);
		CreateWindowA("static", "average value", WS_VISIBLE | WS_CHILD, 420, 7, 100, 15, hWindow, NULL, NULL, NULL);
		CreateWindowA("static", "median value", WS_VISIBLE | WS_CHILD, 545, 7, 100, 15, hWindow, NULL, NULL, NULL);

	}
	catch (const std::exception&)
	{
		createWidgets(hWindow);
	}

}


void printValuesAtTehEnd(HWND hWindow)
{
	for (int i = 0; i < 34; i++)
	{
		double resultForProcentsInPrintValuesAtTheEnd = (((*MyData.allD[i].values.end()) / (*MyData.allD[i].values.begin())));
		if (resultForProcentsInPrintValuesAtTheEnd < 0)
		{
			resultForProcentsInPrintValuesAtTheEnd *= -1;
		}
		CreateWindowA("static", doubleToLPCSTR(resultForProcentsInPrintValuesAtTheEnd), WS_VISIBLE | WS_CHILD, 305, 15 * (i + 1) + 15, 100, 15, hWindow, NULL, NULL, NULL);
	}

	for (int i = 0; i < 34; i++)
	{
		std::sort(MyData.allD[i].values.begin(), MyData.allD[i].values.end(), [](double const& a, double const& b) { return a < b; });
	}

	for (int i = 0; i < 34; i++)
	{
		CreateWindowA("static", doubleToLPCSTR(((MyData.allD[i].sum) / counter)), WS_VISIBLE | WS_CHILD, 420, 15 * (i + 1) + 15, 100, 15, hWindow, NULL, NULL, NULL);
	}

	for (int i = 0; i < 34; i++)
	{
		CreateWindowA("static", doubleToLPCSTR(((MyData.allD[i].values[MyData.allD[i].values.size() / 2]))), WS_VISIBLE | WS_CHILD, 545, 15 * (i + 1) + 15, 100, 15, hWindow, NULL, NULL, NULL);
	}
}

void Save(LPCSTR path)
{
	HANDLE saveFile = CreateFileA(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	int lenOfNewFile = GetWindowTextLength(MY_NOTES);
	char* data = new char[lenOfNewFile];

	lenOfNewFile = GetWindowTextA(MY_NOTES, data, lenOfNewFile);
	DWORD saveFileIterator;
	WriteFile(saveFile, data, lenOfNewFile, &saveFileIterator, NULL);
	
	CloseHandle(saveFile);
	delete[] data;
}
