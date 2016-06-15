/*-----------------------------------------------------/
^ Thanks for using Advanced Firearm Include by Meller. ^
^ This was my first include ever ever made.            ^
/-----------------------------------------------------*/

/****|| Damage Values & Weapons ||****/
	/*               9MM            */
	//     Minium for 9MM are 7.   //
	#define         P250            7
	#define         R8              9
	#define         Glock26         8
	#define         ACP45           12
	#define         TP9SA           16
	#define         TP9SF           16

	/*            Silenced          */
	//  Minium for silenced are 14. //
	#define         APB             14
	#define         Silencer22      34
	#define			MK23            47
	#define         KFOR            31
	#define         LR22            48

	/*             Deagle           */
	//   Minium for Deagle are 28.  //
	#define         Glock18         28
	#define         Glock19         32
	#define         Glock23         41
	#define         Glock40         46
	#define         Glock41         51
	#define         M1911           43
	#define         CZ75            33
	#define         FS92            52
	#define         USPS            45
	#define         P2000           35
	#define         C45             36

	/*            Shotgun           */
	//  Minium for shotgun are 46.  //
	#define         Mossberg500     46
	#define         Remington870    87
	#define         R12             64

	//More weapon models will be added in V2.2

/****|| Variables ||****/
	new HoldingGun[MAX_PLAYERS] = 0,
		HoldingSGun[MAX_PLAYERS] = 0,
		HoldingSGun2[MAX_PLAYERS] = 0,
		HoldingShotgun[MAX_PLAYERS] = 0,
		BulletIDs[1000],
		BulletCount = 0;

/****|| Public.. ||****/
	public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
	{
	    if(hittype == BULLET_HIT_TYPE_OBJECT)
	    {
	   		new Float:fA;
	   		BulletCount++;
			GetPlayerFacingAngle(playerid, fA);
            BulletIDs[BulletCount] = CreateObject(19625, fX, fY, fZ, 0, 0, fA);
            AttachObjectToObject(BulletIDs[BulletCount], hitid, fX, fY, fZ, 0, 0, fA, 1);
	 	}
	    if(hittype == BULLET_HIT_TYPE_VEHICLE)
	    {
	   		new Float:fA;
	   		BulletCount++;
			GetPlayerFacingAngle(playerid, fA);
            BulletIDs[BulletCount] = CreateObject(19625, fX, fY, fZ, 0, 0, fA);
            AttachObjectToVehicle(BulletIDs[BulletCount], hitid, fX, fY, fZ, 0, 0, fA);
	 	}
	    if(hittype == BULLET_HIT_TYPE_PLAYER)
	    {
	   		new Float:fA;
	   		BulletCount++;
			GetPlayerFacingAngle(playerid, fA);
            BulletIDs[BulletCount] = CreateObject(19625, fX, fY, fZ, 0, 0, fA);
            AttachObjectToPlayer(BulletIDs[BulletCount], hitid, fX, fY, fZ, 0, 0, fA);
	 	}
	    if(hittype == BULLET_HIT_TYPE_PLAYER_OBJECT)
	    {
	   		new Float:fA;
	   		BulletCount++;
			GetPlayerFacingAngle(playerid, fA);
            BulletIDs[BulletCount] = CreateObject(19625, fX, fY, fZ, 0, 0, fA);
            AttachObjectToPlayer(BulletIDs[BulletCount], hitid, fX, fY, fZ, 0, 0, fA);
	 	}
	    if((weaponid == 24) || (weaponid == 22) || (weaponid == 23) || (weaponid == 25))
	    {
			if(hittype == BULLET_HIT_TYPE_VEHICLE)
			{
	  			new Float:health;
	    		GetVehicleHealth(hitid, health);
				switch(weaponid)
				{
				    case 24:
				    {
						switch(GetPlayerFirearm(playerid, 1))
						{
						    //Deagle
							case 1: SetVehicleHealth(hitid, health-Glock18);
							case 2: SetVehicleHealth(hitid, health-Glock19);
							case 3: SetVehicleHealth(hitid, health-Glock23);
							case 4: SetVehicleHealth(hitid, health-Glock40);
							case 5: SetVehicleHealth(hitid, health-Glock41);
							case 6: SetVehicleHealth(hitid, health-M1911);
							case 7: SetVehicleHealth(hitid, health-CZ75);
							case 8: SetVehicleHealth(hitid, health-FS92);
							case 9: SetVehicleHealth(hitid, health-USPS);
							case 10: SetVehicleHealth(hitid, health-P2000);
							case 11: SetVehicleHealth(hitid, health-C45);
						}
					}
				    case 22:
				    {
						switch(GetPlayerFirearm(playerid, 2))
						{
						    //9MM
							case 12: SetVehicleHealth(hitid, health-P250);
							case 13: SetVehicleHealth(hitid, health-R8);
							case 14: SetVehicleHealth(hitid, health-Glock26);
							case 15: SetVehicleHealth(hitid, health-ACP45);
							case 16: SetVehicleHealth(hitid, health-TP9SA);
							case 17: SetVehicleHealth(hitid, health-TP9SF);
						}
					}
				    case 23:
				    {
						switch(GetPlayerFirearm(playerid, 3))
						{
				    		//Silenced 9MM
							case 18: SetVehicleHealth(hitid, health-APB);
							case 19: SetVehicleHealth(hitid, health-Silencer22);
							case 20: SetVehicleHealth(hitid, health-MK23);
							case 21: SetVehicleHealth(hitid, health-KFOR);
							case 22: SetVehicleHealth(hitid, health-LR22);
						}
					}
				    case 25:
				    {
						switch(GetPlayerFirearm(playerid, 4))
						{
						    //Shotgun
						    case 23: SetVehicleHealth(hitid, health-Mossberg500);
						    case 24: SetVehicleHealth(hitid, health-Remington870);
						    case 25: SetVehicleHealth(hitid, health-R12);
						}
					}
				}
			}
		}
	    return 1;
	}

	public OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid, bodypart)
	{
	    if(weaponid == 24)
	    {
		    new Float:health;
		    GetPlayerHealth(playerid, health);
            switch(weaponid)
			{
			    case 24:
			    {
					switch(GetPlayerFirearm(issuerid, 1))
					{
					    //Deagle
						case 1: SetPlayerHealth(playerid, health-Glock18);
						case 2: SetPlayerHealth(playerid, health-Glock19);
						case 3: SetPlayerHealth(playerid, health-Glock23);
						case 4: SetPlayerHealth(playerid, health-Glock40);
						case 5: SetPlayerHealth(playerid, health-Glock41);
						case 6: SetPlayerHealth(playerid, health-M1911);
						case 7: SetPlayerHealth(playerid, health-CZ75);
						case 8: SetPlayerHealth(playerid, health-FS92);
						case 9: SetPlayerHealth(playerid, health-USPS);
						case 10: SetPlayerHealth(playerid, health-P2000);
						case 11: SetPlayerHealth(playerid, health-C45);
					}
				}
			    case 22:
			    {
					switch(GetPlayerFirearm(issuerid, 2))
					{
					    //9MM
						case 12: SetPlayerHealth(playerid, health-P250);
						case 13: SetPlayerHealth(playerid, health-R8);
						case 14: SetPlayerHealth(playerid, health-Glock26);
						case 15: SetPlayerHealth(playerid, health-ACP45);
						case 16: SetPlayerHealth(playerid, health-TP9SA);
						case 17: SetPlayerHealth(playerid, health-TP9SF);
					}
				}
				case 23:
				{
					switch(GetPlayerFirearm(issuerid, 3))
					{
				    	//Silenced 9MM
						case 18: SetPlayerHealth(playerid, health-APB);
						case 19: SetPlayerHealth(playerid, health-Silencer22);
						case 20: SetPlayerHealth(playerid, health-MK23);
						case 21: SetPlayerHealth(playerid, health-KFOR);
						case 22: SetPlayerHealth(playerid, health-LR22);
					}
				}
				case 25:
				{
					switch(GetPlayerFirearm(issuerid, 4))
					{
						//Shotgun
						case 23: SetPlayerHealth(playerid, health-Mossberg500);
						case 24: SetPlayerHealth(playerid, health-Remington870);
						case 25: SetPlayerHealth(playerid, health-R12);
					}
				}
			}
		}
	    return 1;
	}

/****|| Set.. ||****/
	stock SetPlayerFirearm(playerid, firearm, ammo, debugging = 0)
	{
	    if((IsPlayerConnected(playerid)) && (firearm > 0) && (firearm < 26))
	    {
	        switch(firearm)
	        {
	            case 1 .. 11:
				{
					GivePlayerWeapon(playerid, 24, ammo);
       				HoldingGun[playerid] = firearm;
				}
				case 12 .. 17:
				{
					GivePlayerWeapon(playerid, 22, ammo);
       				HoldingSGun[playerid] = firearm;
				}
				case 18 .. 22:
				{
					GivePlayerWeapon(playerid, 23, ammo);
       				HoldingSGun2[playerid] = firearm;
				}
				case 23 .. 25:
				{
					GivePlayerWeapon(playerid, 25, ammo);
       				HoldingShotgun[playerid] = firearm;
				}
			}
         	if(debugging == 1)
          	{
         		switch(firearm)
   				{

              		//Deagle
					case 1: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a Glock18, damage will be 28.");
					case 2: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a Glock19, damage will be 32.");
					case 3: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a Glock23, damage will be 41.");
					case 4: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a Glock40, damage will be 46.");
					case 5: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a Glock41, damage will be 51.");
					case 6: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a M1911, damage will be 43.");
					case 7: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a CZ75, damage will be 33.");
					case 8: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a FS92, damage will be 52.");
					case 9: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a USPS, damage will be 45.");
					case 10: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a P2000, damage will be 35.");
					case 11: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a C45, damage will be 36.");
				    //9MM
					case 12: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a P250, damage will be 7.");
					case 13: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a R8, damage will be 9.");
					case 14: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a Glock26, damage will be 8.");
					case 15: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a ACP45, damage will be 12.");
					case 16: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a TP9SA, damage will be 16.");
					case 17: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a TP9SF, damage will be 16.");
				    //Silenced 9MM
					case 18: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a APB, damage will be 14.");
					case 19: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a Silencer22, damage will be 34.");
					case 20: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a MK23, damage will be 47.");
					case 21: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a KFOR, damage will be 31.");
					case 22: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a LR22, damage will be 48.");
	    			//Shotgun
			    	case 23: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a Mossberg500, damage will be 46.");
				    case 24: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a Remington870, damage will be 87.");
	    			case 25: SendClientMessage(playerid, 0xD1D1D1FF, "You have been given a R12, damage will be 64.");
				}
    		}
	    }
	}

	stock ResetPlayerFirearms(playerid)
	{
		HoldingGun[playerid] = 0;
		HoldingSGun[playerid] = 0;
		HoldingSGun2[playerid] = 0;
		HoldingShotgun[playerid] = 0;
	}

/****|| Get.. ||****/
	GetPlayerFirearm(playerid, type)
	{
	    if(type == 1)
	    {
	    	if((IsPlayerConnected(playerid)) && (HoldingGun[playerid] > 0))
	    	{
     			return HoldingGun[playerid];
			}
			else
			{
			    return 0;
  			}
		}
	    else if(type == 2)
	    {
	    	if((IsPlayerConnected(playerid)) && (HoldingSGun[playerid] > 0))
	    	{
     			return HoldingSGun[playerid];
			}
			else
			{
			    return 0;
  			}
		}
	    else if(type == 3)
	    {
	    	if((IsPlayerConnected(playerid)) && (HoldingSGun2[playerid] > 0))
	    	{
     			return HoldingSGun2[playerid];
			}
			else
			{
			    return 0;
  			}
	    }
	    else if(type == 4)
	    {
	    	if((IsPlayerConnected(playerid)) && (HoldingShotgun[playerid] > 0))
	    	{
     			return HoldingShotgun[playerid];
			}
			else
			{
			    return 0;
  			}
	    }
	    else
	        return 0;
	}

	GetFirearmName(id)
	{
 		new nameText[128];
	    if(id > 0 && id < 26)
		{
			switch(id)
   			{
   			    //Deagle
   			    case 1: format(nameText,  128, "GLOCK18");
   			    case 2: format(nameText,  128, "GLOCK19");
   			    case 3: format(nameText,  128, "GLOCK23");
   			    case 4: format(nameText,  128, "GLOCK40");
   			    case 5: format(nameText,  128, "GLOCK41");
   			    case 6: format(nameText,  128, "M1911");
   			    case 7: format(nameText,  128, "CZ75");
   			    case 8: format(nameText,  128, "FS92");
   			    case 9: format(nameText,  128, "USPS");
   			    case 10: format(nameText,  128, "P2000");
   			    case 11: format(nameText,  128, "C45");
   			    //9MM
				case 12: format(nameText,  128, "P250");
				case 13: format(nameText,  128, "R8");
				case 14: format(nameText,  128, "GLOCK26");
				case 15: format(nameText,  128, "ACP45");
				case 16: format(nameText,  128, "TP9SA");
				case 17: format(nameText,  128, "TP9SF");
    			//Silenced 9MM
				case 18: format(nameText,  128, "APB");
				case 19: format(nameText,  128, "SILENCER22");
				case 20: format(nameText,  128, "MK23");
				case 21: format(nameText,  128, "KFOR");
				case 22: format(nameText,  128, "LR22");
 				//Shotgun
    			case 23: format(nameText,  128, "MOSSBERG500");
			    case 24: format(nameText,  128, "REMINGTHON870");
	    		case 25: format(nameText,  128, "R12");
			}
			return nameText;
		}
		else
		{
		    format(nameText,  128, "INVALID");
		    return nameText;
		}
	}
