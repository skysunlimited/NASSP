/***************************************************************************
  This file is part of Project Apollo - NASSP
  Copyright 2004-2005

  ORBITER vessel module: Saturn-specific switches

  Project Apollo is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  Project Apollo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Project Apollo; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  See http://nassp.sourceforge.net/license/ for more details.

  **************************** Revision History ****************************
  *	$Log$
  *	Revision 1.4  2005/09/30 11:22:40  tschachim
  *	Added ECS meters.
  *	
  *	Revision 1.3  2005/08/23 22:18:47  movieman523
  *	SPS switch now works.
  *	
  *	Revision 1.2  2005/08/23 20:13:12  movieman523
  *	Added RCS talkbacks and changed AGC to use octal addresses for EMEM.
  *	
  *	Revision 1.1  2005/08/16 20:55:23  movieman523
  *	Added first saturn-specific switch for Xlunar Inject.
  *	
  **************************************************************************/

class Saturn;

class SaturnToggleSwitch : public ToggleSwitch {
public:
	SaturnToggleSwitch() { sat = 0; };
	void Init(int xp, int yp, int w, int h, SURFHANDLE surf, SwitchRow &row, Saturn *s, int xoffset = 0, int yoffset = 0);

protected:
	Saturn *sat;
};

class SaturnThreePosSwitch : public ThreePosSwitch {
public:
	SaturnThreePosSwitch() { sat = 0; };
	void Init(int xp, int yp, int w, int h, SURFHANDLE surf, SwitchRow &row, Saturn *s);

protected:
	Saturn *sat;
};

class SaturnValveSwitch: public SaturnThreePosSwitch {
public:
	SaturnValveSwitch() { Valve = 0; Indicator = 0; };
	void Init(int xp, int yp, int w, int h, SURFHANDLE surf, SwitchRow &row, Saturn *s, int valve, IndicatorSwitch *ind);
	bool CheckMouseClick(int event, int mx, int my);

protected:
	int Valve;
	IndicatorSwitch *Indicator;
};

class XLunarSwitch : public SaturnToggleSwitch {
public:
	bool CheckMouseClick(int event, int mx, int my);
};

class SaturnSPSSwitch : public SaturnToggleSwitch {
public:
	bool CheckMouseClick(int event, int mx, int my);
};

class SaturnH2PressureMeter : public MeterSwitch {
public:
	void Init(int i, SURFHANDLE surf, SwitchRow &row, Saturn *s);
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);

protected:
	int Index;
	SURFHANDLE NeedleSurface;
	Saturn *Sat;
};

class SaturnO2PressureMeter : public MeterSwitch {
public:
	void Init(int i, SURFHANDLE surf, SwitchRow &row, Saturn *s, ToggleSwitch *o2PressIndSwitch);
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);

protected:
	int Index;
	SURFHANDLE NeedleSurface;
	Saturn *Sat;
	ToggleSwitch *O2PressIndSwitch;	

	void DoDrawSwitch(SURFHANDLE surf, SURFHANDLE needle, double value, int xOffset, int xNeedle);
};

class SaturnCryoQuantityMeter : public MeterSwitch {
public:
	void Init(char *sub, int i, SURFHANDLE surf, SwitchRow &row, Saturn *s);
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);

protected:
	char *Substance;
	int Index;
	SURFHANDLE NeedleSurface;
	Saturn *Sat;
};

class SaturnFuelCellMeter : public MeterSwitch {
public:
	void Init(SURFHANDLE surf, SwitchRow &row, Saturn *s, RotationalSwitch *fuelCellIndicatorsSwitch);

protected:
	SURFHANDLE NeedleSurface;
	Saturn *Sat;
	RotationalSwitch *FuelCellIndicatorsSwitch;
};

class SaturnFuelCellH2FlowMeter : public SaturnFuelCellMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnFuelCellO2FlowMeter : public SaturnFuelCellMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnFuelCellTempMeter : public SaturnFuelCellMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnFuelCellCondenserTempMeter : public SaturnFuelCellMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnCabinMeter : public MeterSwitch {
public:
	void Init(SURFHANDLE surf, SwitchRow &row, Saturn *s);

protected:
	SURFHANDLE NeedleSurface;
	Saturn *Sat;
};

class SaturnSuitTempMeter : public SaturnCabinMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnCabinTempMeter : public SaturnCabinMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnSuitPressMeter : public SaturnCabinMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnCabinPressMeter : public SaturnCabinMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnPartPressCO2Meter : public SaturnCabinMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnRoundMeter : public MeterSwitch {
public:
	void Init(HPEN p0, HPEN p1, SwitchRow &row, Saturn *s);

protected:
	HPEN Pen0;
	HPEN Pen1;
	Saturn *Sat;

	void DrawNeedle (SURFHANDLE surf, int x, int y, double rad, double angle);
};

class SaturnLeftO2FlowMeter : public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnSuitComprDeltaPMeter : public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnSuitCabinDeltaPMeter : public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);

	SURFHANDLE FrameSurface;
};

class SaturnRightO2FlowMeter : public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);

	SURFHANDLE FrameSurface;
};

class SaturnEcsRadTempInletMeter: public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnEcsRadTempPrimOutletMeter: public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnEcsRadTempSecOutletMeter: public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnGlyEvapTempOutletMeter: public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnGlyEvapSteamPressMeter: public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnGlycolDischPressMeter: public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnAccumQuantityMeter: public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};

class SaturnH2oQuantityMeter: public SaturnRoundMeter {
public:
	double QueryValue();
	void DoDrawSwitch(double v, SURFHANDLE drawSurface);
};
