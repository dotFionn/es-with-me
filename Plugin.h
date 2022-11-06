#pragma once
#include <EuroScopePlugIn.h>

#include<string>


using namespace std;
using namespace EuroScopePlugIn;

#define MY_PLUGIN_NAME		"ES WithMe"
#define MY_PLUGIN_VERSION   "1.0.0"
#define MY_PLUGIN_DEVELOPER "Fionn Sperath <fionn@fsperath.de>"
#define MY_PLUGIN_COPYRIGHT "GPL v3"

const int TAG_ITEM_WITHME = 100;
const int TAG_FUNC_TOGGLE_WITHME = 101;

class ESPlugin : public EuroScopePlugIn::CPlugIn
{
private:


public:
	ESPlugin();
	virtual ~ESPlugin();

	void OnGetTagItem(CFlightPlan flightPlan, CRadarTarget RadarTarget, int ItemCode, int TagData, char sItemString[16], int* pColorCode, COLORREF* pRGB, double* pFontSize);

	void OnFunctionCall(int FunctionId, const char* sItemString, POINT Pt, RECT Area);

	bool IsWithMe(string callsign);
	void ToggleWithMe(string callsign);
};