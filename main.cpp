#include <iostream>
#include <windows.h>
#include <vector>
#include <regex>
#include <algorithm>

std::vector<std::wregex> tradeRegexes;
LPCWSTR pathOfExileWindowName = L"Path of Exile";

void InitialiseTradeRegexes() {
	tradeRegexes.push_back(std::wregex(L"@.* Hi, I would like to buy your .* listed for .* in .*"));
	tradeRegexes.push_back(std::wregex(L"@.* Hi, I would like to buy your .* in .*"));
	tradeRegexes.push_back(std::wregex(L"@.* Hi, I'd like to buy your .* for my .* in .*"));
	tradeRegexes.push_back(std::wregex(L"@.* wtb .* listed for .* in .*"));
	tradeRegexes.push_back(std::wregex(L"@.* wtb .* in .*"));
	tradeRegexes.push_back(std::wregex(L"@.* I'd like to buy your .* for my .* in .*"));
	tradeRegexes.push_back(std::wregex(L"@.* Здравствуйте, хочу купить у вас .* за (.*) в лиге.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Здравствуйте, хочу купить у вас .* в лиге.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Здравствуйте, хочу купить у вас .* за (.*) в лиге.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Olá, eu gostaria de comprar o seu item .* listado por .* na.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Olá, eu gostaria de comprar o seu item .* na.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Olá, eu gostaria de comprar seu\(s\) .* pelo\(s\) meu\(s\).*"));
	tradeRegexes.push_back(std::wregex(L"@.* สวัสดี, เราต้องการจะชื้อของคุณ .* ใน ราคา .* ใน.*"));
	tradeRegexes.push_back(std::wregex(L"@.* สวัสดี, เราต้องการจะชื้อของคุณ .* ใน.*"));
	tradeRegexes.push_back(std::wregex(L"@.* สวัสดี เรามีความต้องการจะชื้อ .* ของคุณ ฉันมี .* ใน.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Hi, ich möchte '.*' zum angebotenen Preis von .* in der '.*'-Liga kaufen.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Hi, ich möchte '.*' in der '.*'-Liga kaufen.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Hi, ich möchte '.*' zum angebotenen Preis von '(.*)' in der '(.*)'-Liga kaufen(.*)"));
	tradeRegexes.push_back(std::wregex(L"@.* Bonjour, je souhaiterais t'acheter .* pour .* dans la ligue.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Bonjour, je souhaiterais t'acheter .* dans la ligue.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Bonjour, je voudrais t'acheter .* contre .* dans la ligue.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Hola, quisiera comprar tu .* listado por .* en.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Hola, quisiera comprar tu .* en.*"));
	tradeRegexes.push_back(std::wregex(L"@.* Hola, me gustaría comprar tu\(s\) .* por mi .* en.*"));
	tradeRegexes.push_back(std::wregex(L"@.* 안녕하세요, .*에 .*\(으\)로 올려놓은 .*을\(를\) 구매하고 싶습니다.*"));
	tradeRegexes.push_back(std::wregex(L"@.* 안녕하세요, .*에 올려놓은 .*을\(를\) 구매하고 싶습니다.*"));
	tradeRegexes.push_back(std::wregex(L"@.* 안녕하세요, .*에 올려놓은.* 을\(를\) 제 .*\(으\)로 구매하고 싶습니다.*"));
}

void SendPasteToPathOfExileWindow() {

	HWND pathOfExileHWND = FindWindow(NULL, pathOfExileWindowName);
	HWND oldFocusedWindow = GetForegroundWindow();

	int key_count = 8;

	INPUT* input = new INPUT[key_count];
	for (int i = 0; i < key_count; i++)
	{
		input[i].ki.dwFlags = 0;
		input[i].type = INPUT_KEYBOARD;
	}

	// Enter down
	input[0].ki.wVk = VK_RETURN;
	input[0].ki.wScan = MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC);

	// Enter up
	input[1].ki.dwFlags = KEYEVENTF_KEYUP;
	input[1].ki.wVk = input[0].ki.wVk;
	input[1].ki.wScan = input[0].ki.wScan;

	// Ctrl down
	input[2].ki.wVk = VK_CONTROL;
	input[2].ki.wScan = MapVirtualKey(VK_CONTROL, MAPVK_VK_TO_VSC);

	// V down
	input[3].ki.wVk = 0x56; // Virtual key code for 'v'
	input[3].ki.wScan = MapVirtualKey(0x56, MAPVK_VK_TO_VSC);

	// Ctrl up
	input[4].ki.dwFlags = KEYEVENTF_KEYUP;
	input[4].ki.wVk = input[2].ki.wVk;
	input[4].ki.wScan = input[2].ki.wScan;

	// V up
	input[5].ki.dwFlags = KEYEVENTF_KEYUP;
	input[5].ki.wVk = input[3].ki.wVk;
	input[5].ki.wScan = input[3].ki.wScan;

	// Enter down
	input[6].ki.wVk = VK_RETURN; // Virtual key code for 'enter'
	input[6].ki.wScan = MapVirtualKey(VK_RETURN, MAPVK_VK_TO_VSC);

	// Enter up
	input[7].ki.dwFlags = KEYEVENTF_KEYUP;
	input[7].ki.wVk = input[0].ki.wVk;
	input[7].ki.wScan = input[0].ki.wScan;

	ShowWindow(pathOfExileHWND, SW_SHOWNORMAL);
	Sleep(50);
	SetForegroundWindow(pathOfExileHWND);
	Sleep(50);
	SendInput(key_count, (LPINPUT)input, sizeof(INPUT));
	Sleep(50);
	SetForegroundWindow(oldFocusedWindow);
	delete input;
}

std::wstring GetClipboardText()
{
	if (OpenClipboard(NULL)) {
		HANDLE hData = GetClipboardData(CF_UNICODETEXT);
		if (hData) {
			auto pszText = static_cast<WCHAR*>(GlobalLock(hData));
			std::wstring text(pszText);
			GlobalUnlock(hData);
			CloseClipboard();
			return text;
		}
		CloseClipboard();
	}
	return L"";
}

bool IsClipboardTrade(std::wstring clipboardText) {
	return std::any_of(tradeRegexes.begin(), tradeRegexes.end(), [clipboardText](std::wregex reg) {
		return std::regex_match(clipboardText, reg);
		});
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_CLIPBOARDUPDATE) {
		std::cout << "Clipboard update" << std::endl;
		if (IsClipboardTrade(GetClipboardText())) {
			std::cout << "Sending trade message" << std::endl;
			SendPasteToPathOfExileWindow();
			Sleep(500);
			return NULL;
		}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void CreateMessageWindow() {
	static const char* class_name = "DUMMY_CLASS";
	static const char* name = "DUMMY";
	WNDCLASSEX wx = {};
	wx.cbSize = sizeof(WNDCLASSEX);
	wx.lpfnWndProc = WindowProcedure;
	wx.hInstance = GetModuleHandle(NULL);
	wx.lpszClassName = (LPCWSTR)class_name;

	if (RegisterClassEx(&wx)) {
		auto test = CreateWindowEx(0, (LPCWSTR)class_name, (LPCWSTR)name, 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);
		if (test) {
			AddClipboardFormatListener(test);
		}
	}
}

int main(void) {
	CreateMessageWindow();
	InitialiseTradeRegexes();
	std::cout << "Poe Instant Trade Ready" << std::endl;
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0) != 0) {
		DispatchMessage(&msg);
	}
}