
class CfgMovesBasic 
{
	class DefaultDie;
	class ManActions
	{
		Merlin_Cargo_BAF="Merlin_Cargo_BAF";
		Merlin_Cargo01_BAF="Merlin_Cargo01_BAF";
		Merlin_Pilot_BAF="Merlin_Pilot_BAF";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		
		///Merlin Animations///
		
		class Merlin_Cargo_BAF: Crew
		{
			file="\DEGA_Merlins\Data\Anim\Merlin_Cargo";
			connectTo[]=
			{
				"Merlin_KIA_Cargo_BAF",
				1
			};
			speed=1e+010;
		};
		class Merlin_KIA_Cargo_BAF: DefaultDie
		{
			actions="DeadActions";
			file="\DEGA_Merlins\Data\Anim\Merlin_KIA_Cargo";
			speed=1e+010;
			terminal=1;
			soundEnabled=0;
			looped=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		
		class Merlin_Cargo01_BAF: Crew
		{
			file="\DEGA_Merlins\Data\Anim\Merlin_Cargo01";
			connectTo[]=
			{
				"Merlin_KIA_Cargo_BAF",
				1
			};
			speed=1e+010;
		};
		
		class Merlin_Pilot_BAF: Crew
		{
			file="\DEGA_Merlins\Data\Anim\Merlin_Pilot";
			connectTo[]=
			{
				"Merlin_KIA_Pilot_BAF",
				1
			};
			speed=1e+010;
		};
		class Merlin_KIA_Pilot_BAF: DefaultDie
		{
			actions="DeadActions";
			file="\DEGA_Merlins\Data\Anim\Merlin_Kia_Pilot";
			speed=1e+010;
			terminal=1;
			soundEnabled=0;
			looped=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};		
	};
};
class CfgMovesWomen: CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{	
		Merlin_Cargo_BAF="crew";
		Merlin_Cargo01_BAF="crew";
		Merlin_Pilot_BAF="crew";	
	};
};