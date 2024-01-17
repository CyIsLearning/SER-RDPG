#include "algorithm"
#include "vector"
#include "iostream"
int nCycle=12;//length of the control cycle
double dTargetDiameter=0.6;//target diameter value
double dThreshold=0.09;//threshold that decides whether to store the transition
double dCriterion=0.0;
vector <double> d_vTemperature(nCycle);//temperature data during the control cycle
vector <double> d_vDiameter(nCycle);//diameter data during the control cycle
vector <double> d_vTension(nCycle);//tension data during the control cycle
vector <double> d_vDrawingVel(nCycle);//drawing velocity data during the control cycle
vector <vector<double>> v_Transition;//transition vector
vector <vector <vector<double>>> v_Memory;//memory vector
double d_iTemperature;//i-th Temperature value
double d_iDiameter;//i-th Diameter value
double d_iTension;//i-th Tension value
double d_iDrawingVel;//i-th Drawing Velocity value

for (int i=0;i<nCycle;++i)
{
	d_vTemperature.push_back(d_iTemperature);
	d_vDiameter.push_back(d_iDiameter);
	d_vTension.push_back(d_iTension);
	d_vDrawingVel.push_back(d_iDrawingVel);
	dCriterion+=abs(d_iDiameter-dTargetDiameter);
}
dCriterion/=nCycle;
if (dCriterion<=dThreshold)
{
	//store the transition
	v_Transition.push_back(d_vTemperature);
	v_Transition.push_back(d_vDiameter);
	v_Transition.push_back(d_vTension);
	v_Transition.push_back(d_vDrawingVel);
	v_Memory.push_back(v_Transition);
}
