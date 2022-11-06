#include "stdafx.h"
#include "Plugin.h"
#include <string>
#include <set>

using namespace std;

set<string> withMe = {};
string pluginName = MY_PLUGIN_NAME;

ESPlugin::ESPlugin() : EuroScopePlugIn::CPlugIn(EuroScopePlugIn::COMPATIBILITY_CODE, MY_PLUGIN_NAME, MY_PLUGIN_VERSION, MY_PLUGIN_DEVELOPER, MY_PLUGIN_COPYRIGHT)
{	
	string version = MY_PLUGIN_VERSION;
	DisplayUserMessage(pluginName.c_str(), "Initialisation", ("Version " + version + " loaded").c_str(), true, false, false, false, false);

	RegisterTagItemType("With Me", TAG_ITEM_WITHME);
	RegisterTagItemFunction("Toggle With Me", TAG_FUNC_TOGGLE_WITHME);
}

ESPlugin::~ESPlugin()
{}

void ESPlugin::OnGetTagItem(CFlightPlan flightPlan, CRadarTarget RadarTarget, int ItemCode, int TagData, char sItemString[16], int* pColorCode, COLORREF* pRGB, double* pFontSize)
{
	string callsign = _strdup(flightPlan.GetCallsign());
	if (ItemCode == TAG_ITEM_WITHME) {
		string display = "\xac";

		if (IsWithMe(callsign)) {
			display = "\xa4";
		}
		
		strcpy_s(sItemString, sizeof sItemString, display.c_str());
	}
}

void ESPlugin::OnFunctionCall(int FunctionId, const char* sItemString, POINT Pt, RECT Area)
{
	CFlightPlan flightPlan = FlightPlanSelectASEL();
	char* callsign = _strdup(flightPlan.GetCallsign());
	if (FunctionId == TAG_FUNC_TOGGLE_WITHME) {
		ToggleWithMe(callsign);
	}
}

bool ESPlugin::IsWithMe(string callsign)
{
	bool isWithMe = withMe.count(callsign) != 0;
	
	return isWithMe;
}

void ESPlugin::ToggleWithMe(string callsign)
{
	if (IsWithMe(callsign)) {
		withMe.erase(callsign);
	}
	else {
		withMe.insert(callsign);
	}

	string str = "";
	for (set<string>::iterator it = withMe.begin(); it != withMe.end(); ++it) {
		str = str + *it + " ";
	}
}
