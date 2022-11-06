#pragma once
#include <EuroScopePlugIn.h>


using namespace std;
using namespace EuroScopePlugIn;

#define MY_PLUGIN_NAME		"ES WithMe"
#define MY_PLUGIN_VERSION   "1.0.0"
#define MY_PLUGIN_DEVELOPER "Fionn Sperath <fionn@fsperath.de>"
#define MY_PLUGIN_COPYRIGHT "GPL v3"


class ESPlugin : public EuroScopePlugIn::CPlugIn
{
private:


public:
	ESPlugin();
	virtual ~ESPlugin();

};