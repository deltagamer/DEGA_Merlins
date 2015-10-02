#include "Crewanimations.hpp"
#include "config_extra.hpp"

class CfgVehicles
{
	class AllVehicles;
	class thingX;
	class Air: AllVehicles
	{
		class NewTurret;
		class ViewPilot;
	};
	class Helicopter: Air
	{
		class Turrets
		{
			class MainTurret;
		};
		class NewTurret;
		class AnimationSources;
		class HitPoints;
	};
	class Helicopter_Base_F: Helicopter
	{
		class RotorLibHelicopterProperties;	// External class reference
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitHRotor;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;		
		};
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class AnimationSources;
		class Eventhandlers;
		class ViewOptics;
	};
	class PlaneWreck;
	class HelicopterWreck;
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////Merlin////////////////////////////////////
///////////////////////////////////////Base/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class Helicopter_Base_H : Helicopter_Base_F {};
	class DEGA_Merlin_Base: Helicopter_Base_H
	{
//		expansion = 2; // BAF
		scope = 1;
		scopeCurator = 0;		// 2 means available from Zeus, whereas 0 means hidden			
		side = 1;
		faction = BLU_F;
		
	    author = "Deltagamer";	

        driveOnComponent[] = {"Wheels"};		
		
        AGM_FastRoping = 1;         //  X    Z    Y
        AGM_FastRoping_Positions[] = {{0.6, -5, -0.5}, {-0.2, -5, -0.5}};		
		
		tf_RadioType_api = "tf_anarc210";
		tf_hasLRradio_api = 1; // 1 = true, 0 = false
		tf_isolatedAmount_api = 0.2;	
		
		selectionHRotorStill = "velka vrtule staticka";
		selectionHRotorMove = "velka vrtule blur";
		selectionVRotorStill = "mala vrtule staticka";
		selectionVRotorMove = "mala vrtule blur";

		slingLoadMemoryPoint = "slingLoad0";
		slingLoadMaxCargoMass = 10000;
		slingLoadOperator = 1;	
        liftForceCoef = 2.5;

        memoryPointDriverOptics = "slingCamera";	/// what memory point is the origin of the camera			
		
		class Library {libTextDesc = $STR_BAF_CFGVEHICLES_BAF_MERLIN_HC3_D_LIBRARY0;}; 		
		
		picture = "\DEGA_Merlins\Data\UI\picture_merlin_ca.paa";
		icon = "\DEGA_Merlins\Data\UI\icon_merlin_ca.paa";
		mapSize = 20;

		memoryPointsGetInDriver = "pos codriver";		
		memoryPointsGetInDriverDir = "pos codriver dir";
		
		// Crew definition
		crewVulnerable = true;
		crew = "B_Helipilot_F";
		typicalCargo[]={"B_Soldier_F","B_Soldier_F"};		
		driverAction = "Merlin_Pilot_BAF";
		cargoIsCoDriver[]={true,false};
		GetInAction = GetInHigh;
		GetOutAction = GetOutHigh; 
		cargoAction[]=
		{	
		    Merlin_Cargo_BAF, Merlin_Cargo01_BAF, Merlin_Cargo_BAF, Merlin_Cargo01_BAF, Merlin_Cargo01_BAF, 
			Merlin_Cargo_BAF, Merlin_Cargo01_BAF, Merlin_Cargo_BAF, Merlin_Cargo01_BAF, Merlin_Cargo01_BAF, 
			Merlin_Cargo_BAF, Merlin_Cargo01_BAF, Merlin_Cargo01_BAF, Merlin_Cargo_BAF, passenger_flatground_crosslegs,
			passenger_flatground_crosslegs, passenger_flatground_crosslegs, passenger_flatground_generic04, passenger_flatground_generic04, passenger_flatground_generic02,
			passenger_flatground_generic04, passenger_flatground_generic02, passenger_flatground_generic02, passenger_flatground_crosslegs
		};
		memoryPointsGetInCargo[] = {"pos cargo"};
		memoryPointsGetInCargoDir[] = {"pos cargo dir"};

		maxSpeed = 309; // according to our library
		accuracy=1.5;
		cost=10000000;
		armor=60;
		damageResistance = 0.00555;
		vehicleClass = "Air";
		laserScanner = true;
		MainRotorSpeed = 1.0;
		backRotorSpeed =  1.0;
		gearRetracting=true;
		gearUpTime=1;
		gearDownTime=1;		
		
		// Guns and equipment
		weapons[] = {CMFlareLauncher};
		magazines[] = {120Rnd_CMFlare_Chaff_Magazine,120Rnd_CMFlare_Chaff_Magazine,120Rnd_CMFlare_Chaff_Magazine};
		LockDetectionSystem = 0x00111000;
		IncommingMisslieDetectionSystem = CM_Missile;
		irScanRangeMin=0;
		irScanRangeMax=1000;
		nightVision=1;
		
		Simulation = "HelicopterX";		
		
		transportSoldier = 21;
		transportMaxBackpacks = 28;
		
		radarType = 4;
		enableManualFire = false;		
		
		selectionFireAnim = "zasleh";

		threat[]={0.3, 0.3, 0.3};
		destrType=DestructWreck;				

		supplyRadius = 5; // needs the memory point "doplnovani"			
		
		class TransportBackpacks
		{
			class _xx_B_Parachute
			{
				backpack = "B_Parachute";
				count = 20;
			};
		};
		class TransportItems
		{
			class _xx_FirstAidKit
			{
				name = "FirstAidKit";
				count = 10;
			};
			class _xx_Medikit
			{
				name = "Medikit";
				count = 2;
			};
		};			
		class Reflectors
		{
			class Right
			{
				color[] = {7000,7500,10000};	/// defines red, green, blue and alpha components of the light
				ambient[] = {70,75,100};		/// the same definition format for colouring the environment around
				intensity = 50;					/// how much does the light shine (in some strange units, just tweak until it is satisfying), rough approximation is intensity = (brightness * 50) ^ 2
				size = 1;						/// defines the visible size of light, has not much of an effect now
				innerAngle = 20;				/// angle from light direction vector where the light is at full strength
				outerAngle = 135;				/// angle from light direction vector where the light is completely faded out
				coneFadeCoef = 10;				/// coefficient of fading the light between inner and outer cone angles
				position = "Light_R_pos";		/// name of memory point in model to take the origin of the light
				direction = "Light_R_dir";		/// name of memory point in the model to make a vector of direction of light from it's position
				hitpoint = "Light_R_hitpoint";	/// name of hitpoint selection in hitpoint lod of the model to be affected by damage
				selection = "Light_R";			/// name of selection in visual lods of the model that are going to be hidden while the light is off
				useFlare = true;				/// boolean switch if the light produces flare or not
				flareSize = 15;					/// how big is the flare, using the same metrics as intensity
				flareMaxDistance = 300;			/// maximum distance where the flare is drawn
				dayLight = false;				/// boolean switch if the light is used during day or not
				class Attenuation
				{
					start = 0;					/// offset of start of the attenuation
					constant = 0;				/// constant attenuation of the light in any distance from source
					linear = 1;					/// coefficient for linear attenuation
					quadratic = 1;				/// coefficient for attenuation with square of distance from source
					hardLimitStart = 100;		/// distance from source where the light intensity decreases for drawing
					hardLimitEnd = 200;			/// distance from source where the light is not displayed (shorter distances increase performance)
				};
			};
			class Left: Right
			{
				position = "Light_L_pos";
				direction = "Light_L_dir";
				hitpoint = "Light_L_hitpoint";
				selection = "Light_L";
			};
		};
		aggregateReflectors[] = {{"Left", "Right"}};	/// aggregates both sources into one to increase performance		
		class pilotCamera				/// camera for pilot to observe sling loading
        {
            class OpticsIn				/// what is seen if player switches to optics
            {		
                class Wide
                {
                    opticsDisplayName 	= "W";	/// used in case the UI has place to display optics mode
                    initAngleX			= 0;	/// X-axis rotation and its limits
					minAngleX			= -0; 	/// X-axis rotation and its limits
					maxAngleX			= +0;	/// X-axis rotation and its limits
                    initAngleY			= 0; 	/// Y-axis rotation and its limits
					minAngleY			= -0;  	/// Y-axis rotation and its limits
					maxAngleY			= +0; 	/// Y-axis rotation and its limits
                    initFov				= 0.5;	/// Field of view size settings
					minFov				= 0.5;	/// Field of view size settings
					maxFov				= 0.5;	/// Field of view size settings
                    visionMode[] 		= {"Normal","NVG", "TI"};	/// what vision modes are available
                    thermalMode[] 		= {0,1};			/// not necessary as there is no TI mode defined, but just in case
                    gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d"; /// some optics model
				};
				showMiniMapInOptics				= true;	/// allows showing GPS mini map in optics
				showUAVViewpInOptics			= true;	/// allows showing UAV feed in this optics
				showSlingLoadManagerInOptics 	= true;		/// allows displaying of Sling Loading Assistant
            };
            minTurn                 = 0; 		//turn
            maxTurn                 = 0; 		//turn
            initTurn                = 0; 		//turn
            minElev                 = 80; 		//turn
            maxElev                 = 80; 		//turn
            initElev                = 80; 		//turn
            maxXRotSpeed            = 0.5; 		// movement speed
            maxYRotSpeed            = 0.5; 		// movement speed
            pilotOpticsShowCursor   = 1; 		//to show aimCursor (is useful to see plane direction)
            controllable            = false; 	// set false to have static camera, true to have moving like a turret
        };		
		class MarkerLights
		{
			class GreenStill 
			{
				name = "light_nav_right";
				color[] = {0.0, 0.8, 0.0};
				ambient[] = {0.0, 0.08, 0.0};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.15;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
			};	
			class RedBlinking 
			{
				name = "light_nav_top";
				color[] = {0.9, 0.15, 0.1};
				ambient[] = {0.09, 0.015, 0.01};
				intensity = 50;
				blinking = 1;
				blinkingPattern[] = {0.1, 0.9};
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.2;
				drawLightCenterSize = 0.04;
			};
			class RedStill 
			{
				name = "light_nav_left";
				color[] = {0.8, 0.0, 0.0};
				ambient[] = {0.08, 0.0, 0.0};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.15;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
			};	
		};		
		class AnimationSources: AnimationSources
		{
			class dvere_l
			{
				source="door";
				animPeriod=1.3;
				initPhase=-1;				
				sound = "MetalOldBigDoorsSound";				
			};
			class dvere_p
			{
				source="door";
				animPeriod=1.3;
				initPhase=-1;				
				sound = "MetalOldBigDoorsSound";				
			};			
			class rampa
			{
				source="door";
				animPeriod=6;
				initPhase=0;
				sound = "ServoRampSound_2";				
			};

			class HidePIPMFDCO
			{
				source="user";
				animPeriod=0;
				initPhase=0;
			};	

			class HidePIPMFDPI
			{
				source="user";
				animPeriod=0;
				initPhase=0;
			};			
		};
		class RenderTargets /// class for all Picture-in-Picture
		{
			class camera
			{
				renderTarget = "rendertarget3";
				class CameraView1
				{
					pointPosition		= "FLIR_begin"; 	/// memory point of PiP origin
					pointDirection		= "FLIR_end"; 	/// memory point of PiP direction
					renderQuality 		= 4;			/// what quality should the PiP be
					renderVisionMode 	= 0;			/// zero means standard vision
					fov 				= 0.466;			/// what is the angle of the PiP field of view
				}; 	
			};
		};			
		class MFD {};
		class UserActions
		{
			class CloseRear // disabled
			{
				displayName= "<t color='#FF0000'>Close Ramp</t>"; //Red
				displayNameDefault = ""; 
				position="";
				radius=3.6;
				onlyForplayer=false;
				condition="this doorPhase ""rampa"" > 0.45 AND (((player == (driver this) or player == (gunner this))) && (alive this))"; //  AND (player == (gunner this) && (alive this)) //  AND Alive(this)
				statement="this animateDoor [""rampa"",0];";
				priority=9;
			};
			class OpenRearRamp
			{
				displayName= "<t color='#FF0000'>Open Ramp</t>"; //Red
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=false;
				condition="this doorPhase ""rampa"" < 0.55 AND (((player == (driver this) or player == (gunner this))) && (alive this))";
				statement="this animateDoor [""rampa"",1];";
				priority=9;
			}; 			
			class COmfdpip1ON
			{
				displayName= "<t color='#ffff00'>Turn On FLIR MFD</t>"; //Yellow
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=true;
				condition="this animationPhase ""copip"" < 0.5 AND (player == (gunner this) && (alive this))";
				statement="this animate [""copip"",1];";
				priority=13;
			}; 	
			class COmfdpip1OFF
			{
				displayName= "<t color='#ffff00'>Turn Off FLIR MFD</t>"; //Yellow
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=true;
				condition="this animationPhase ""copip"" > 0.5 AND (player == (gunner this) && (alive this))";
				statement="this animate [""copip"",0];";
				priority=13;
			}; 
			class Pimfdpip1ON
			{
				displayName= "<t color='#ffff00'>Turn On FLIR MFD</t>"; //Yellow
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=true;
				condition="this animationPhase ""copip1"" < 0.5 AND (player == (driver this) && (alive this))";
				statement="this animate [""copip1"",1];";
				priority=13;
			}; 	
			class Pimfdpip1OFF
			{
				displayName= "<t color='#ffff00'>Turn Off FLIR MFD</t>"; //Yellow
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=true;
				condition="this animationPhase ""copip1"" > 0.5 AND (player == (driver this) && (alive this))";
				statement="this animate [""copip1"",0];";
				priority=13;
			}; 	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			class OpenRdoor
			{
				displayName= "<t color='#FF0000'>Open Right Door</t>"; //Red
				position="doplnovani"; //axis_door_side_pop
				radius= 12;
				onlyForplayer=false;
				condition="this doorPhase ""dvere_p"" > 0.5 AND ((this getCargoIndex player) isEqualTo 0)";
				statement="this animateDoor [""dvere_p"",0];this animateDoor [""dvere_p_pop"",0];"; //dvere_p slide part
			};
			class CloseRdoor
			{
				displayName= "<t color='#FF0000'>Close Right Door</t>"; //Red
				position="doplnovani";  //axis_door_side_pop
				radius= 12;
				onlyForplayer=false;
				condition="this doorPhase ""dvere_p"" < 0.5 AND ((this getCargoIndex player) isEqualTo 0)";
				statement="this animateDoor [""dvere_p"",1];this animateDoor [""dvere_p_pop"",1];";
			};
			class OpenLdoor
			{
				displayName= "<t color='#FF0000'>Open Crew Door</t>"; //Red
				position="doplnovani";
				radius= 12;
				onlyForplayer=false;
				condition="this doorPhase ""dvere_l"" > 0.5 AND ((this getCargoIndex player) isEqualTo 1)";
				statement="this animateDoor [""dvere_l"",0];this animateDoor [""dvere_l_pop"",0];";
			};
			class CloseLdoor
			{
				displayName= "<t color='#FF0000'>Close Crew Door</t>"; //Red
				position="doplnovani";
				radius= 12;
				onlyForplayer=false;
				condition="this doorPhase ""dvere_l"" < 0.5 AND ((this getCargoIndex player) isEqualTo 1)";
				statement="this animateDoor [""dvere_l"",1];this animateDoor [""dvere_l_pop"",1];";
			};				
		};
		class CargoTurret;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret //Gunner
			{
				body="FLIR_turret";
				gun="FLIR_gun";
				animationSourceBody="FLIR_turret";
				animationSourceGun="FLIR_gun";
                memoryPointGunnerOptics= "FLIR_end";								
				gunBeg="FLIR_end"; //gunBeg=endpoint of the gun
			    gunEnd="FLIR_begin"; //gunEnd=chamber of the gun	
				memoryPointGun = "FLIR_end";
	            stabilizedInAxes = 3;
				gunnername = "Co-Pilot";
				isCopilot = 1;
				
				minElev=-40; maxElev=+20; initElev=0;
				minTurn=-360; maxTurn=360; initTurn=0;
				//minTurn=-120; maxTurn=120; initTurn=0;
				
		        memoryPointsGetInGunner = "pos codriver";		
		        memoryPointsGetInGunnerDir = "pos codriver dir";					

				turretInfoType = "RscOptics_UAV_gunner";
				weapons[] = {"Laserdesignator_mounted"};
				
				magazines[] = {Laserbatteries};
				proxyType = CPGunner;
				
				inGunnerMayFire = true;
				gunnerAction = Merlin_Pilot_BAF;
				gunnerGetInAction = GetInHigh;
				gunnerGetOutAction = GetOutHigh;
				gunnerOpticsEffect[] = {};
				gunnerOpticsModel = "";

                class OpticsIn 
                {
	                class WideNGS
	                {
		                opticsDisplayName = "W";
		                initAngleX = 0;
		                minAngleX = -35;
		                maxAngleX = 10;
		                initAngleY = 0;
		                minAngleY = -100;
		                maxAngleY = 100;
		                initFov = 0.466;
		                minFov = 0.466;
		                maxFov = 0.466;
		                visionMode[] = {"Normal","NVG", "Ti"};
		                thermalMode[] = {0, 1};
		                gunnerOpticsColor[]= {0.15000001,1,0.15000001,1};
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
		                directionStabilized=0;
		                opticsPPEffects[]=
		                {
			                "OpticsCHAbera2",
			                "OpticsBlur2"
		                };
	                };
	                class Wide 
	                {
		                opticsDisplayName = "W";
		                initAngleX = 0;
		                minAngleX = -35;
		                maxAngleX = 10;
		                initAngleY = 0;
		                minAngleY = -100;
		                maxAngleY = 100;
		                initFov = 0.466;
		                minFov = 0.466;
		                maxFov = 0.466;
		                visionMode[] = {"Normal","NVG", "Ti"};
		                thermalMode[] = {0, 1};
		                gunnerOpticsColor[]= {0.15000001,1,0.15000001,1};
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
		                //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
		                directionStabilized=1;
		                opticsPPEffects[]=
		                {
			                "OpticsCHAbera2",
			                "OpticsBlur2"
		                };
		                gunnerOpticsEffect[]=
		                {
			                "TankCommanderOptics1"
		                };
	                };
	                class WideL: Wide 
	                {
		                opticsDisplayName = "WL";
		                initFov = 0.2;
		                minFov = 0.2;
		                maxFov = 0.2;
		                //gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
		                //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
		                gunnerOpticsColor[]= {0,0,0,1};
		                directionStabilized=1;	// Camera Stabilizing Boolean
		                opticsPPEffects[]=
		                {
			                "OpticsCHAbera2",
			                "OpticsBlur2"
		                };
	                };
	                class Medium : Wide 
	                {
		                opticsDisplayName = "M";
		                initFov = 0.1;
		                minFov = 0.1;
		                maxFov = 0.1;
		                directionStabilized=1;	// Camera Stabilizing Boolean
		                gunnerOpticsColor[]= {0,0,0,1};
		                //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
	                };
	                class Narrow : Wide 
	                {
		                opticsDisplayName = "N";
		                gunnerOpticsColor[]= {0,0,0,1};
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
		                //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
		                directionStabilized=1;	// Camera Stabilizing Boolean
		                initFov = 0.02;
		                minFov = 0.02;
		                maxFov = 0.02;
	                };
	                class Narrower : Wide 
	                {
		                opticsDisplayName = "N";
		                gunnerOpticsColor[]= {0,0,0,1};
		                gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
		                //gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
		                directionStabilized=1;	// Camera Stabilizing Boolean
		                initFov = 0.01;
		                minFov = 0.01;
		                maxFov = 0.01;
	                };
                };		
				class OpticsOut
				{
					class Monocular // 1x-3.5x
					{
						initAngleX=0; minAngleX=-30; maxAngleX=+30;
						initAngleY=0; minAngleY=-100; maxAngleY=+100;
						initFov=1.1; minFov=0.133; maxFov=1.1;
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
				startEngine=false;
				gunnerHasFlares = false;
			};
			class CargoTurret_01: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerAction 				= "passenger_inside_4"; //gunner_mortar	/// generic animation for sitting inside with rifle ready
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos loadmaster";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos loadmaster dir";	/// direction of get in action
				gunnerName 					= "Loadmaster (Right)";	/// name of the position in the Action menu
				proxyIndex 					= 27;					/// what cargo proxy is used according to index in the model
				maxElev 					= 40;					/// what is the highest possible elevation of the turret
				minElev 					= -40;					/// what is the lowest possible elevation of the turret
				maxTurn 					= 55;					/// what is the left-most possible turn of the turret
				minTurn 					= -45;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 1;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				enabledByAnimationSource 	= "";				/// doesn't work unless the said animation source is 1
			};	
			class CargoTurret_02: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerAction 				= "passenger_inside_4"; //gunner_mortar	/// generic animation for sitting inside with rifle ready
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos codriver";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos codriver dir";	/// direction of get in action
				gunnerName 					= "Crewmaster (left)";	/// name of the position in the Action menu
				proxyIndex 					= 28;					/// what cargo proxy is used according to index in the model
				maxElev 					= 40;					/// what is the highest possible elevation of the turret
				minElev 					= -40;					/// what is the lowest possible elevation of the turret
				maxTurn 					= 40;					/// what is the left-most possible turn of the turret
				minTurn 					= -25;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 1;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				enabledByAnimationSource 	= "";				/// doesn't work unless the said animation source is 1
			};	
			class CargoTurret_03: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerAction 				= "passenger_inside_3";	/// generic animation for sitting inside with rifle ready
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo right";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo dir right";	/// direction of get in action
				gunnerName 					= "Passenger (Right Seat)";	/// name of the position in the Action menu
				proxyIndex 					= 26;					/// what cargo proxy is used according to index in the model
				maxElev 					= 15;					/// what is the highest possible elevation of the turret
				minElev 					= -40;					/// what is the lowest possible elevation of the turret
				maxTurn 					= 100;					/// what is the left-most possible turn of the turret
				minTurn 					= 40;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 1;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				enabledByAnimationSource 	= "rampa";				/// doesn't work unless the said animation source is 1				
			};
			class CargoTurret_04: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerAction 				= "passenger_inside_3";	/// generic animation for sitting inside with rifle ready
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo left";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo dir left";	/// direction of get in action
				gunnerName 					= "Passenger (Left Seat)";	/// name of the position in the Action menu
				proxyIndex 					= 25;					/// what cargo proxy is used according to index in the model
				maxElev 					= 15;					/// what is the highest possible elevation of the turret
				minElev 					= -40;					/// what is the lowest possible elevation of the turret
				maxTurn 					= -40;					/// what is the left-most possible turn of the turret
				minTurn 					= -100;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 1;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				enabledByAnimationSource 	= "rampa";				/// doesn't work unless the said animation source is 1						
			};		
		};		
		class HitPoints:HitPoints
		{
			class HitHull {armor=1;material=51;name="NEtrup";visual="trup";passThrough=0.5;}; // disabled points from model
			class HitEngine {armor=0.5;material=51;name="motor";visual="motor";passThrough=0.5;};
			class HitAvionics {armor=0.15;material=51;name="elektronika";visual="elektronika";passThrough=0.2;};
			class HitVRotor {armor=0.3;material=51;name="mala vrtule";visual="mala vrtule staticka";passThrough=0.1;};
			class HitHRotor {armor=0.2;material=51;name="velka vrtule";visual="velka vrtule staticka";passThrough=0.1;};
			class HitGlass1:HitGlass1 {armor=0.5;};
			class HitGlass2:HitGlass2 {armor=0.5;};
			class HitGlass3:HitGlass3 {armor=0.5;};
			class HitGlass4:HitGlass4 {armor=0.5;};
			class HitGlass5:HitGlass5 {armor=0.5;};
			class HitGlass6 {armor=0.5;material=-1;name="glass6";visual="glass6";passThrough=0;};
			class HitGlass7 {armor=0.5;material=-1;name="glass7";visual="glass7";passThrough=0;};
			class HitGlass8 {armor=0.5;material=-1;name="glass8";visual="glass8";passThrough=0;};
			class HitGlass9 {armor=0.5;material=-1;name="glass9";visual="glass9";passThrough=0;};
			class HitGlass10{armor=0.5;material=-1;name="glass10";visual="glass10";passThrough=0;};
			class HitGlass11{armor=0.5;material=-1;name="glass11";visual="glass11";passThrough=0;};
			class HitGlass12{armor=0.5;material=-1;name="glass12";visual="glass12";passThrough=0;};
			class HitGlass13{armor=0.5;material=-1;name="glass13";visual="glass13";passThrough=0;};
			class HitGlass14{armor=0.5;material=-1;name="glass14";visual="glass14";passThrough=0;};
			class HitGlass15{armor=0.5;material=-1;name="glass15";visual="glass15";passThrough=0;};
			class HitGlass16{armor=0.5;material=-1;name="glass16";visual="glass16";passThrough=0;};
			class HitGlass17{armor=0.5;material=-1;name="glass17";visual="glass17";passThrough=0;};
			class HitGlass18{armor=0.5;material=-1;name="glass18";visual="glass18";passThrough=0;};
			class HitGlass19{armor=0.5;material=-1;name="glass19";visual="glass19";passThrough=0;};
			class HitGlass20{armor=0.5;material=-1;name="glass20";visual="glass20";passThrough=0;};			
		};
		
		// materials
		class Damage
		{
			tex[]={};
			mat[]={
			"DEGA_Merlins\Data\merlin_int_01.rvmat",
			"DEGA_Merlins\Data\merlin_int_01_damage.rvmat",
			"DEGA_Merlins\Data\merlin_int_01_destruct.rvmat",
			
			"DEGA_Merlins\Data\merlin_int_02.rvmat",
			"DEGA_Merlins\Data\merlin_int_02_damage.rvmat",
			"DEGA_Merlins\Data\merlin_int_02_destruct.rvmat",			
			
			"DEGA_Merlins\Data\Merlin_glass.rvmat",
			"DEGA_Merlins\Data\Merlin_glass_damage.rvmat",
			"DEGA_Merlins\Data\Merlin_glass_damage.rvmat",

			"DEGA_Merlins\Data\MerlinHc3_2_BAF.rvmat",
			"DEGA_Merlins\Data\MerlinHc3_2_BAF_damage.rvmat",
			"DEGA_Merlins\Data\MerlinHc3_2_BAF_destruct.rvmat",	
			
			"DEGA_Merlins\Data\MerlinHc3_1_BAF.rvmat",
			"DEGA_Merlins\Data\MerlinHc3_1_BAF_damage.rvmat",
			"DEGA_Merlins\Data\MerlinHc3_1_BAF_destruct.rvmat"			
			};
		};
		
		attenuationEffectType="HeliAttenuation";
		emptySound[]=
		{
			"",
			0,
			1
		};
		soundGeneralCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_default_int_1",
			1,
			1,
			100
		};
		soundGeneralCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_default_int_2",
			1,
			1,
			100
		};
		soundGeneralCollision3[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_default_int_3",
			1,
			1,
			100
		};
		soundCrashes[]=
		{
			"soundGeneralCollision1",
			0.33000001,
			"soundGeneralCollision2",
			0.33000001,
			"soundGeneralCollision3",
			0.33000001
		};
		soundLandCrashes[]=
		{
			"emptySound",
			0
		};
		soundBuildingCrash[]=
		{
			"soundGeneralCollision1",
			1,
			"soundGeneralCollision2",
			1,
			"soundGeneralCollision3",
			1
		};
		soundArmorCrash[]=
		{
			"soundGeneralCollision1",
			1,
			"soundGeneralCollision2",
			1,
			"soundGeneralCollision3",
			1
		};
		soundWoodCrash[]=
		{
			"soundGeneralCollision1",
			1,
			"soundGeneralCollision2",
			1,
			"soundGeneralCollision3",
			1
		};
		soundBushCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_1",
			1,
			1,
			100
		};
		soundBushCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_2",
			1,
			1,
			100
		};
		soundBushCollision3[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_3",
			1,
			1,
			100
		};
		soundBushCrash[]=
		{
			"soundBushCollision1",
			0.33000001,
			"soundBushCollision2",
			0.33000001,
			"soundBushCollision3",
			0.33000001
		};
		soundWaterCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_water_ext_1",
			1,
			1,
			100
		};
		soundWaterCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_water_ext_2",
			1,
			1,
			100
		};
		soundWaterCrashes[]=
		{
			"soundWaterCollision1",
			0.5,
			"soundWaterCollision2",
			0.5
		};
		soundDammage[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_crash_default_int_1",
			10,
			1
		};
		soundGetIn[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_02\open",
			1,
			1
		};
		soundGetOut[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_02\close",
			1,
			1,
			50
		};
		soundEngineOnInt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_int_start_v2",
			0.31622776,
			1
		};
		soundEngineOnExt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_ext_start_v2",
			2.2387211,
			1,
			600
		};
		soundEngineOffInt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_int_stop_v2",
			0.31622776,
			1
		};
		soundEngineOffExt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_ext_stop_v2",
			2.2387211,
			1,
			600
		};
		soundLocked[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_1",
			1,
			1
		};
		soundIncommingMissile[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_3",
			1,
			1.5
		};
		occludeSoundsWhenIn=0.56234133;
		obstructSoundsWhenIn=0.31622776;
		rotorDamageInt[]=
		{
			"A3\Sounds_F\vehicles\air\noises\heli_damage_rotor_int_1",
			1,
			1
		};
		rotorDamageOut[]=
		{
			"A3\Sounds_F\vehicles\air\noises\heli_damage_rotor_ext_1",
			2.5118864,
			1,
			300
		};
		rotorDamage[]=
		{
			"rotorDamageInt",
			"rotorDamageOut"
		};
		tailDamageInt[]=
		{
			"A3\Sounds_F\vehicles\air\noises\heli_damage_tail",
			1,
			1
		};
		tailDamageOut[]=
		{
			"A3\Sounds_F\vehicles\air\noises\heli_damage_tail",
			1,
			1,
			300
		};
		tailDamage[]=
		{
			"tailDamageInt",
			"tailDamageOut"
		};
		landingSoundInt0[]=
		{
			"A3\Sounds_F\vehicles\air\noises\landing_wheels_small_int1",
			1,
			1,
			100
		};
		landingSoundInt1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\landing_wheels_small_int2",
			1,
			1,
			100
		};
		landingSoundInt[]=
		{
			"landingSoundInt0",
			0.5,
			"landingSoundInt1",
			0.5
		};
		landingSoundOut0[]=
		{
			"A3\Sounds_F\vehicles\air\noises\landing_wheels_ext1",
			1.7782794,
			1,
			100
		};
		landingSoundOut1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\landing_wheels_ext2",
			1.7782794,
			1,
			100
		};
		landingSoundOut[]=
		{
			"landingSoundOut0",
			0.5,
			"landingSoundOut1",
			0.5
		};
		slingCargoAttach0[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_engineUpEndINT",
			1,
			1
		};
		slingCargoAttach1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_1hookLock",
			1,
			1,
			80
		};
		slingCargoAttach[]=
		{
			"slingCargoAttach0",
			"slingCargoAttach1"
		};
		slingCargoDetach0[]=
		{
			"A3\Sounds_F\dummysound",
			1,
			1
		};
		slingCargoDetach1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_1hookUnlock",
			1,
			1,
			80
		};
		slingCargoDetach[]=
		{
			"slingCargoDetach0",
			"slingCargoDetach1"
		};
		slingCargoDetachAir0[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_unhook_air_int",
			1,
			1
		};
		slingCargoDetachAir1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_unhook_air_ext",
			1,
			1,
			80
		};
		slingCargoDetachAir[]=
		{
			"slingCargoDetach0",
			"slingCargoDetach1"
		};
		slingCargoRopeBreak0[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_rope_break_int",
			1,
			1
		};
		slingCargoRopeBreak1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_rope_break_ext",
			1,
			1,
			80
		};
		slingCargoRopeBreak[]=
		{
			"slingCargoDetach0",
			"slingCargoDetach1"
		};
		gearUpExt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_01\gear_up_OUT",
			1,
			1,
			1000
		};
		gearUpInt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_01\gear_up_IN",
			1,
			1,
			100
		};
		gearUp[]=
		{
			"gearUpInt",
			"gearUpExt"
		};
		gearDownInt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_01\gear_down_IN",
			1,
			1,
			100
		};
		gearDownExt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_01\gear_down_OUT",
			1,
			1,
			1000
		};
		gearDown[]=
		{
			"gearDownInt",
			"gearDownExt"
		};
		class Sounds
		{
			class EngineExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_ext_engine",
					1.2589254,
					1,
					900
				};
				frequency="rotorSpeed";
				volume="camPos*(rotorSpeed-0.72)*4";
			};
			class RotorExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_ext_rotor",
					1.7782794,
					1,
					2000
				};
				frequency="rotorSpeed * rotorSpeed * (1 - rotorThrust/6)";
				volume="camPos*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)";
				cone[]={1.6,3.1400001,1.6,0.94999999};
			};
			class RotorNoiseExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\Heli_Transport_02\rotor_swist",
					0.70794576,
					1,
					800
				};
				frequency=1;
				volume="camPos * (rotorThrust factor [0.7, 0.9])";
				cone[]={0.69999999,1.3,1,0};
			};
			class EngineInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_int_engine",
					1,
					1
				};
				frequency="rotorSpeed";
				volume="(1-camPos)*(rotorSpeed-0.75)*4";
			};
			class RotorInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_int_rotor",
					1.2589254,
					1
				};
				frequency="rotorSpeed * rotorSpeed * (1 - rotorThrust/6)";
				volume="(1-camPos)*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)";
			};
			class TransmissionDamageExt_phase1
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_1",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="camPos * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class TransmissionDamageExt_phase2
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_2",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="camPos * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class TransmissionDamageInt_phase1
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_1",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="(1 - camPos) * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class TransmissionDamageInt_phase2
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_2",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="(1 - camPos) * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class damageAlarmInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
					0.31622776,
					1
				};
				frequency=1;
				volume="engineOn * (1 - camPos) * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0.0, 0.001])";
			};
			class damageAlarmExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
					0.2238721,
					1,
					20
				};
				frequency=1;
				volume="engineOn * camPos * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0, 0.001])";
			};
			class rotorLowAlarmInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
					0.31622776,
					1
				};
				frequency=1;
				volume="engineOn * (1 - camPos) * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
			};
			class rotorLowAlarmExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
					0.2238721,
					1,
					20
				};
				frequency=1;
				volume="engineOn * camPos * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
			};
			class scrubLandInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\wheelsInt",
					1,
					1,
					100
				};
				frequency=1;
				volume="2 * (1-camPos) * (scrubLand factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
			};
			class scrubLandExt
			{
				sound[]=
				{
					"A3\Sounds_F\dummysound",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * (scrubLand factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
			};
			class scrubBuildingInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\wheelsInt",
					1,
					1,
					100
				};
				frequency=1;
				volume="(1-camPos) * (scrubBuilding factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
			};
			class scrubBuildingExt
			{
				sound[]=
				{
					"A3\Sounds_F\dummysound",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * (scrubBuilding factor[0.02, 0.05])";
			};
			class scrubTreeInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubTreeInt",
					1,
					1,
					100
				};
				frequency=1;
				volume="(1 - camPos) * ((scrubTree) factor [0, 0.01])";
			};
			class scrubTreeExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubTreeExt",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * ((scrubTree) factor [0, 0.01])";
			};
			class RainExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\rain1_ext",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * (rain - rotorSpeed/2) * 2";
			};
			class RainInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\rain1_int",
					1,
					1,
					100
				};
				frequency=1;
				volume="(1-camPos)*(rain - rotorSpeed/2)*2";
			};
			class SlingLoadDownExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT",
					1,
					1,
					500
				};
				frequency=1;
				volume="camPos*(slingLoadActive factor [0,-1])";
			};
			class SlingLoadUpExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineUpEXT",
					1,
					1,
					500
				};
				frequency=1;
				volume="camPos*(slingLoadActive factor [0,1])";
			};
			class SlingLoadDownInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineDownINT",
					1,
					1,
					500
				};
				frequency=1;
				volume="(1-camPos)*(slingLoadActive factor [0,-1])";
			};
			class SlingLoadUpInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineUpINT",
					1,
					1,
					500
				};
				frequency=1;
				volume="(1-camPos)*(slingLoadActive factor [0,1])";
			};
			class WindInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\wind_closed",
					0.70794576,
					1,
					50
				};
				frequency=1;
				volume="(1-camPos)*(speed factor[5, 50])*(speed factor[5, 50])";
			};
			class GStress
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\vehicle_stress2d",
					0.70794576,
					1,
					50
				};
				frequency=1;
				volume="engineOn * (1-camPos) * ((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))";
			};
			class SpeedStress
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\vehicle_stress3",
					0.70794576,
					1,
					50
				};
				frequency=1;
				volume="(1-camPos)*(speed factor[40,60])";
			};
		};
		class SoundsExt
		{
			class SoundEvents
			{
			};
			class Sounds
			{
				class EngineExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_ext_engine",
						1.2589254,
						1,
						900
					};
					frequency="rotorSpeed";
					volume="camPos*(rotorSpeed-0.72)*4";
				};
				class RotorExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_ext_rotor",
						1.7782794,
						1,
						2000
					};
					frequency="rotorSpeed * rotorSpeed * (1 - rotorThrust/6)";
					volume="camPos*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)";
					cone[]={1.6,3.1400001,1.6,0.94999999};
				};
				class RotorNoiseExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\Heli_Transport_02\rotor_swist",
						0.70794576,
						1,
						800
					};
					frequency=1;
					volume="camPos * (rotorThrust factor [0.7, 0.9])";
					cone[]={0.69999999,1.3,1,0};
				};
				class EngineInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_int_engine",
						1,
						1
					};
					frequency="rotorSpeed";
					volume="(1-camPos)*(rotorSpeed-0.75)*4";
				};
				class RotorInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\Heli_Transport_02\Heli_Transport_02_int_rotor",
						1.2589254,
						1
					};
					frequency="rotorSpeed * rotorSpeed * (1 - rotorThrust/6)";
					volume="(1-camPos)*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)";
				};
				class TransmissionDamageExt_phase1
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_1",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="camPos * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class TransmissionDamageExt_phase2
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_2",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="camPos * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class TransmissionDamageInt_phase1
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_1",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="(1 - camPos) * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class TransmissionDamageInt_phase2
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_2",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="(1 - camPos) * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class damageAlarmInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
						0.31622776,
						1
					};
					frequency=1;
					volume="engineOn * (1 - camPos) * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0.0, 0.001])";
				};
				class damageAlarmExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
						0.2238721,
						1,
						20
					};
					frequency=1;
					volume="engineOn * camPos * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0, 0.001])";
				};
				class rotorLowAlarmInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
						0.31622776,
						1
					};
					frequency=1;
					volume="engineOn * (1 - camPos) * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
				};
				class rotorLowAlarmExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
						0.2238721,
						1,
						20
					};
					frequency=1;
					volume="engineOn * camPos * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
				};
				class scrubLandInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\wheelsInt",
						1,
						1,
						100
					};
					frequency=1;
					volume="2 * (1-camPos) * (scrubLand factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
				};
				class scrubLandExt
				{
					sound[]=
					{
						"A3\Sounds_F\dummysound",
						1,
						1,
						100
					};
					frequency=1;
					volume="camPos * (scrubLand factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
				};
				class scrubBuildingInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\wheelsInt",
						1,
						1,
						100
					};
					frequency=1;
					volume="(1-camPos) * (scrubBuilding factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
				};
				class scrubBuildingExt
				{
					sound[]=
					{
						"A3\Sounds_F\dummysound",
						1,
						1,
						100
					};
					frequency=1;
					volume="camPos * (scrubBuilding factor[0.02, 0.05])";
				};
				class scrubTreeInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\scrubTreeInt",
						1,
						1,
						100
					};
					frequency=1;
					volume="(1 - camPos) * ((scrubTree) factor [0, 0.01])";
				};
				class scrubTreeExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\scrubTreeExt",
						1,
						1,
						100
					};
					frequency=1;
					volume="camPos * ((scrubTree) factor [0, 0.01])";
				};
				class RainExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\noises\rain1_ext",
						1,
						1,
						100
					};
					frequency=1;
					volume="camPos * (rain - rotorSpeed/2) * 2";
				};
				class RainInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\noises\rain1_int",
						1,
						1,
						100
					};
					frequency=1;
					volume="(1-camPos)*(rain - rotorSpeed/2)*2";
				};
				class SlingLoadDownExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT",
						1,
						1,
						500
					};
					frequency=1;
					volume="camPos*(slingLoadActive factor [0,-1])";
				};
				class SlingLoadUpExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\SL_engineUpEXT",
						1,
						1,
						500
					};
					frequency=1;
					volume="camPos*(slingLoadActive factor [0,1])";
				};
				class SlingLoadDownInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\SL_engineDownINT",
						1,
						1,
						500
					};
					frequency=1;
					volume="(1-camPos)*(slingLoadActive factor [0,-1])";
				};
				class SlingLoadUpInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\SL_engineUpINT",
						1,
						1,
						500
					};
					frequency=1;
					volume="(1-camPos)*(slingLoadActive factor [0,1])";
				};
				class WindInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\wind_closed",
						0.70794576,
						1,
						50
					};
					frequency=1;
					volume="(1-camPos)*(speed factor[5, 50])*(speed factor[5, 50])";
				};
				class GStress
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\noises\vehicle_stress2d",
						0.70794576,
						1,
						50
					};
					frequency=1;
					volume="engineOn * (1-camPos) * ((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))";
				};
				class SpeedStress
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\noises\vehicle_stress3",
						0.70794576,
						1,
						50
					};
					frequency=1;
					volume="(1-camPos)*(speed factor[40,60])";
				};
			};
		};		
	};
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////AW101 BAF Merlin HC3///////////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Merlin_HC3_BAF: DEGA_Merlin_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		scopeCurator = 2;		// 2 means available from Zeus, whereas 0 means hidden		
		displayname = AW101 BAF Merlin HC3;
		model = "\DEGA_Merlins\MerlinHC3_BAF";	
		_generalMacro = "DEGA_Merlin_HC3_BAF";			
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};
			class CargoTurret_01: CargoTurret_01 {};
			class CargoTurret_02: CargoTurret_02 {};
			class CargoTurret_03: CargoTurret_03 {};	
			class CargoTurret_04: CargoTurret_04 {};			
		};
	};	
////////////////////////////////////////////////////////////////////////////////
////////////////////////////AW101 BAF Merlin HC3A///////////////////////////////
////////////////////////////////////////////////////////////////////////////////		
	class DEGA_Merlin_HC3A_BAF: DEGA_Merlin_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		scopeCurator = 2;		// 2 means available from Zeus, whereas 0 means hidden			
		displayname = AW101 BAF Merlin HC3A;
		model = "\DEGA_Merlins\MerlinHC3A_BAF";	
		_generalMacro = "DEGA_Merlin_HC3A_BAF";			
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};
			class CargoTurret_01: CargoTurret_01 {};
			class CargoTurret_02: CargoTurret_02 {};
			class CargoTurret_03: CargoTurret_03 {};
			class CargoTurret_04: CargoTurret_04 {};				
		};
	};	
};