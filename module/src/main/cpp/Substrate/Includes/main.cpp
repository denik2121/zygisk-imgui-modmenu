#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>
#include "Includes/il2cpptypes.h"
#include "Unity/ESP.h"
#include <string>
#include <stdint.h>
#include <cstring>
#include <string.h>
#include <wchar.h>
#include <endian.h>
#include <GLES2/gl2.h>
#include <dlfcn.h>
#include <GLES2/gl2.h>
#include <dlfcn.h>
#include <list>
#include <vector>
#include <string.h>
#include <GLES2/gl2.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include "Includes/Macros.h"
#include "Includes/XorS.h"
#include "Icon.h"
#include "HOOK.h"

#include "Includes/amapLog.h"


#include "Chams.h"


#include "Unity/Vector3.h"
#include "Unity/Vector2.h"
#include "Unity/Quaternion.h"



float upval=1.0f;
float upval2=1.0f;
float upval3= 2.0f;

ESP espOverlay;









using namespace std;
std::string utf16le_to_utf8(const std::u16string &u16str) {
    if (u16str.empty()) { return std::string(); }
    const char16_t *p = u16str.data();
    std::u16string::size_type len = u16str.length();
    if (p[0] == 0xFEFF) {
        p += 1;
        len -= 1;
    }

    std::string u8str;
    u8str.reserve(len * 3);

    char16_t u16char;
    for (std::u16string::size_type i = 0; i < len; ++i) {

        u16char = p[i];

        if (u16char < 0x0080) {
            u8str.push_back((char) (u16char & 0x00FF));
            continue;
        }
        if (u16char >= 0x0080 && u16char <= 0x07FF) {
            u8str.push_back((char) (((u16char >> 6) & 0x1F) | 0xC0));
            u8str.push_back((char) ((u16char & 0x3F) | 0x80));
            continue;
        }
        if (u16char >= 0xD800 && u16char <= 0xDBFF) {
            uint32_t highSur = u16char;
            uint32_t lowSur = p[++i];
            uint32_t codePoint = highSur - 0xD800;
            codePoint <<= 10;
            codePoint |= lowSur - 0xDC00;
            codePoint += 0x10000;
            u8str.push_back((char) ((codePoint >> 18) | 0xF0));
            u8str.push_back((char) (((codePoint >> 12) & 0x3F) | 0x80));
            u8str.push_back((char) (((codePoint >> 06) & 0x3F) | 0x80));
            u8str.push_back((char) ((codePoint & 0x3F) | 0x80));
            continue;
        }
        {
            u8str.push_back((char) (((u16char >> 12) & 0x0F) | 0xE0));
            u8str.push_back((char) (((u16char >> 6) & 0x3F) | 0x80));
            u8str.push_back((char) ((u16char & 0x3F) | 0x80));
            continue;
        }
    }

    return u8str;
}
typedef struct _monoString {
    void *klass;
    void *monitor;
    int length;
    char chars[1];
    int getLength() {
        return length;
    }
    const char *toChars(){
        u16string ss((char16_t *) getChars(), 0, getLength());
        string str = utf16le_to_utf8(ss);
        return str.c_str();
    }
    char *getChars() {
        return chars;
    }
    std::string get_string() {

      return std::string(toChars());
}
} monoString;

monoString *CreateMonoString(const char *str) {
    monoString *(*String_CreateString)(void *instance, const char *str) = (monoString *(*)(void *, const char *))getAbsoluteAddress("libil2cpp.so", 0x1760904);

    return String_CreateString(NULL, str);
}




bool gloves0, gloves1, gloves2, gloves3, gloves4, gloves5, gloves6, gloves7, gloves8, gloves9 = false;

bool Auth = false;
float AimFov = 30.0f;
bool BYPPAASSSS= false,KICK,KICKENEMY,RIRIRIEIRRIRIEJEDJ,DDDHDJDJ,SHSBSNSB,LLPFOFFFK;




extern "C" {
	
	
JNIEXPORT void JNICALL 
Java_androidx_appcompat_app_B_getContext(JNIEnv *env, jobject top, jobject contexxt){
    string id = getSignatures(env, contexxt);
    string org = OBFUSCATE("E89B158E4BCF988EBD09EB83F5378E87");

    jclass erfeevbf = env->FindClass("androidx/appcompat/app/B");
    jmethodID fjfj3yvee = env->GetStaticMethodID(erfeevbf, "EncodeStr", "(Ljava/lang/String;)Ljava/lang/String;");
    jmethodID jmethodId = env->GetStaticMethodID(erfeevbf, "DecodeStr", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    jobject fh8wgufnvwas = env->CallStaticObjectMethod(erfeevbf, fjfj3yvee, env->NewStringUTF(OBFUSCATE("776B8FFDF8E140C8")));
    const char* rhvuhevhu = env->GetStringUTFChars((jstring) fh8wgufnvwas, nullptr);
    string uehfhwevrurev = rhvuhevhu;
    string hh = get(uehfhwevrurev, OBFUSCATE("http://flickmods.ru/~}.txt"));
    jobject jobject1 = env->CallStaticObjectMethod(erfeevbf, jmethodId, env->NewStringUTF(hh.c_str()), env->NewStringUTF(OBFUSCATE("UaVXKEoh0Z8602ZM")));
    const char* string1 = env->GetStringUTFChars((jstring) jobject1, nullptr);
    string string2 = string1;

    if (string2.find(GetDeviceId(env)) != string::npos) {
        MakeToast(env, contexxt, OBFUSCATE("Authorization succed! flick Thx"), 2);
        Auth = true;
    } else if (id != org) {
        Auth = false;
        int *p = 0;
        *p = 0;
    } else {
        Auth = false;
    }
}




JNIEXPORT jboolean 
JNICALL 
Java_androidx_appcompat_app_B_NeLez(JNIEnv *env, jclass clazz) {
    jclass ndbvhbsbvhdbvhs = env->FindClass("androidx/appcompat/app/B");
    jmethodID fjvuinweownvwue = env->GetStaticMethodID(ndbvhbsbvhdbvhs, "EncodeStr", "(Ljava/lang/String;)Ljava/lang/String;");
    jobject fh8wgufnvwas = env->CallStaticObjectMethod(ndbvhbsbvhdbvhs, fjvuinweownvwue, env->NewStringUTF("776B8FFDF8E140C8"));
    const char* bdbvbdvdhbvh = env->GetStringUTFChars((jstring) fh8wgufnvwas, nullptr);
    string uehfhufuuwwevrurev = bdbvbdvdhbvh;
    string hh = get(uehfhufuuwwevrurev, OBFUSCATE("http://flickmods.ru/~}.txt"));
    jclass jclass4 = env->FindClass("androidx/appcompat/app/B");
    jmethodID jmethodId4 = env->GetStaticMethodID(jclass4, "DecodeStr", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    jobject jobject4 = env->CallStaticObjectMethod(jclass4, jmethodId4, env->NewStringUTF(hh.c_str()), env->NewStringUTF(OBFUSCATE("UaVXKEoh0Z8602ZM")));
    const char* string4 = env->GetStringUTFChars((jstring) jobject4, nullptr);
    string string5 = string4;
    string wtf = GetDeviceId(env);
    if (string5.find(wtf) != string::npos && Auth) {
        return true;
    } else {
        return false;
    }
}

 
 
 
 
 
 
 
 struct My_Patches {
    MemoryPatch Sh,antiban0,antiban1, antiban2, antiban3, antiban4,antiban5, antiban6, antiban7, antiban8,antiban9, antiban10,
            antiban11, antiban12, antiban13, antiban14,antiban15, antiban16, antiban17, antiban18,antiban19, antiban20,
            antiban21, antiban22, antiban23, antiban24,antiban25, antiban26, antiban27, antiban28,antiban29, antiban30,
            antiban31, antiban32, antiban33, antiban34,antiban35, antiban36, antiban37, antiban38,antiban39, antiban40,
            antiban41, antiban42, antiban43, antiban44,antiban45, antiban46, antiban47, antiban48,antiban49, antiban50,
            antiban51, antiban52, antiban53, antiban54,antiban55, antiban56, antiban57, antiban58,antiban59, antiban60,
            antiban61, antiban62, antiban63, antiban64,antiban65, antiban66, antiban67, antiban68,antiban69, antiban70,
            antiban71, antiban72, antiban73, antiban74,antiban75, antiban76, antiban77, antiban78,antiban79, antiban80,
            antiban81, antiban82, antiban83, antiban84,antiban85, antiban86, antiban87, antiban88,antiban89, antiban90,
            antiban91, antiban92, antiban93, antiban94,antiban95, antiban96, antiban97, antiban98,antiban99, antiban100, AIM, NORECOIL,DONT,MONEY,MOVE,GRA,
            antiban101, antiban102, antiban103, antiban104,antiban105, antiban106, antiban107, antiban108,antiban109, antiban110,
            antiban111, antiban112, antiban113, antiban114,antiban115, antiban116, antiban117, antiban118,antiban119, antiban120,
            antiban121, antiban122, antiban123, antiban124,antiban125, antiban126, antiban127, antiban128,antiban129, antiban130,
            antiban131, antiban132, antiban133, antiban134,antiban135, antiban136, antiban137, antiban138,antiban139, antiban140,
            antiban141, antiban142, antiban143, antiban144,antiban145, antiban146, antiban147, antiban148,antiban149, antiban150,FOVVV1,FOVVV2,FOVVV3,FOVVV4,FOVVV5,FOVVV6,FOVVV7,
            antiban151, antiban152, antiban153, antiban154,antiban155, antiban156,bypass,shot,ammo1,ammo2,recoil,pl1,pl2,radar,fire,fride,drop,fastplant,boom,nn,gg1,gg2,antiflash3,gg3,gg4,gg5,gg6,gg7,antiflash1,fast1,fast2,fast3,fast4,fast5,antiflash2;
} hexPatches;
  const char *libName = "libil2cpp.so";
const char *XD = "libunity.so";


JNIEXPORT jstring JNICALL
    Java_androidx_appcompat_app_Main_apk(
        JNIEnv *env,
        jobject activityObject) {
    jstring str = env->NewStringUTF("    FLiCK MODS | P1\nToken Auth");// do not earse the space this for normal text view
    return str;
}
    JNIEXPORT jstring JNICALL
    Java_androidx_appcompat_app_Main_down(
        JNIEnv *env,
        jobject activityObject) {
    jstring str = env->NewStringUTF("Version 0.19.3 F1[P1]");
        return str;
    }
    
   

	
	
	
	
	
	JNIEXPORT jobjectArray  JNICALL
Java_androidx_appcompat_app_Main_getFeatures(
        JNIEnv *env,
        jobject activityObject) {
    jobjectArray ret;
    //text = CRASH
    //ButtonSwitch = HL1
    //Button = HL2
    //SeekBar = Example = SeekBar_Name_0_2
    //Hide icon = KIRA
    
	
	const char *features[] = {
            "CRASH_Chams Menu︎", //0
            "HL1_Color Chams", //1
            "HL1_Wireframe Chams", //2
            "HL1_Glow Chams", //3
            "HL1_Shading Chams", //4
            "HL1_Outline Chams", //5
            "HL1_Rainbow Chams", //6
            "Text_Chams Settings",//7
            "SeekBar_Color Red_255_255", //8
            "SeekBar_Color Green_0_255", //9
            "SeekBar_Color Blue_0_255", //10
            "SeekBar_Outline Width_3_20", //11
            "SeekBar_Outline Wireframe_0_20", //12
		    
		
		    "CRASH_Knife Menu",//13
            "HL2_SET-KNIFE",//14
            "SeekBar_ID:KNIFE:M9_0_6", //15
            "SeekBar_ID:KNIFE:Butterfly_0_6", //16
            "SeekBar_ID:KNIFE:Karambit_0_6", //17
            "SeekBar_ID:KNIFE:jKommando_0_6", //18
            "SeekBar_ID:KNIFE:Flip_0_6", //19
            "SeekBar_ID:KNIFE:Kunai_0_7", //20
            "SeekBar_ID:KNIFE:Scorpion_0_5", //21
            "SeekBar_ID:Tanto:_0_6", //22
			
			"CRASH_Weapon Menu",//23
            "HL2_SET-WEAPON",//24
           	"SeekBar_ID:Weapon:_0_24", //25

            "CRASH_Gloves Menu",//26
	        "HL1_SET-GLOVES",//27
           	"SeekBar_ID:Gloves:_0_11", //28

	       
		
		

      
            
            "CRASH_Player Menu",//29
			"HL1_God Mode",//30
            "HL1_Rapid Fire",//31
            "HL1_Kill teammates",//32
            "HL1_Air-Jump",//33
            "HL1_Drop Knife",//34
            "HL1_Radar Hack",//35
            "HL1_Infinity Ammo",//36
            "HL1_Wallshot",//37
            "HL1_NoRecoil",//38
            
            "CRASH_Esp NEW",//39
			"HL1_Esp",//40
			"HL1_Esp Line",//41
			"HL1_Esp Box",//42
		    "HL1_Esp Distance",//43
			"HL1_Esp Health[soon]",//44
			"HL1_Esp Rainbow",//45
			"SeekBar_Box color_0_7",//46
			"SeekBar_Height Box_1_5",//47
			"SeekBar_Width Box_1_5",//48
			"SeekBar_Line size_1_5",//49
			
			"CRASH_Aim Menu",//50
			"HL1_Aimbot",//51
			"SeekBar_Aim Fov_0_360",//52
			"CRASH_!!!silent включаем в меню игры!!!!",//53
			"HL1_Head-Silent",//54
			"HL1_Body-Silent",//55
			
			"CRASH_Misc Menu",//56
			"HL1_Telekill",//57
			"HL1_Masskill",//58
			"HL1_Set-speed",//59
            "SeekBar_SpeedHack_4_30",//60
			"HL1_Antiflash",//61
			"HL1_Nuck",//62
			"HL1_Enemy Nuck",//63
			"HL1_Enemy Flash",//64
			"HL1_Enemy Smoke",//65
			
			
		    "HL1_Dont return respawn",//66
			"HL1_Move before time",//67
			"HL1_Immune grenade",//68
			"HL1_Money hack",//69
			"HL1_Spoof ID",//70
			"HL1_Spoof clan tag",//71
			
			"HL1_Fast Bomb",//72
			"HL1_Auto Defuse",//73
			"HL1_Plant Hack",//74
			"HL1_Fast Plant",//75
			"HL1_Hands Pos",//76
			
			"SeekBar_X_1_5",//77
			"SeekBar_Y_1_5",//78
			"SeekBar_Z_1_5",//79
			
			"CRASH_Menu Settings",
            "KIRA_Make Icon invisible",
			
	  
           
            };

    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

   // pthread_t ptid;
    //pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}



bool setbomb,telekill,masskill,
GODMOD,wallshot,MONEY,DEFUS,FIRE,AMMO,DROP,RADAR,
PLANT,FRIDE,RESPAWN,MMHACK,SEC,JUMPHACK,
SETWEAPON,noweapon,noweapon2,NORECOIL,aim,
ch1,ch2,ch3,FAST,boom,antiban,grenadenuke,
nick,move,SUCK= false;
bool usedist, useangle,spawngrenade,autodef,UP,DEFSEC,XUI,chatspam,handspos,V2,bggvv,TEST,NUCKI = false;
bool Awp, VVv, Boom, Tre = false;
bool Akr, Fury = false;
int  JJ = 1;
int SDDD;
int dbdbdhdhdd =0;

bool Gg22, Relic = false;
bool Fn, Lea = false;
bool Mm40, Mons = false;
bool Dea, Yak = false;
bool Fiv, Pois = false;
bool M4a1, Bubb = false;
bool Mm4m, Sam = false;
bool Mm60, Mecha = false;
bool Usp, Gen = false;
bool Pp350, Radi = false;
bool chams, wireframe,rainbow,outline, glow,shading, rgbchams,ANTI= false;
float X1, Y1, Z1;
float aimdist, aimangles;
int Lol = 0;
bool m91,m92,m93,m94,m95,m96,b1,b2,b3,b4,b5,b6,ka1,ka2,ka3,ka4,ka5,ka6,ka7,ka8,J1,J2,J3,J4,J5,f1,f2,f3,f4,f5,f6,k1,k2,k3,k4,k5,k6,k7,s1,s2,s3,s4,s5,t1,t2,t3,t4,t5,t6 = false;
bool loggedin = true;
bool cc = true;
float sp,cr = 4.0f;
bool FOV1,FOV2,FOV3,HOP= false;
bool headsilent,bodysilent=false;		
bool  killlll,CEREE,MMR1 = false;
bool ENEMYNUCKI,XXX,ENEMYFLASH,GEMS,ASS,HOOK2,HOOK3,HOOK4,HOOK5,HOOK6= false;
bool ESP2,FLASH777,GHK,GLODDDDD,
        ESPTeamminate,
        ESPLine,
        ESPBox,
        ESPDistance,
        ESPHealth,
        ESPCrosshair,
       ESPRGB,FUCKFDDDD,xbdbdhxxhxh, ESPWeapon,
        ESPName = false;
Color color; /*Цвет есп*/
int ESPBoxStyle = 1; /*Настройка коробки*/
int ESPLineLocation = 2.4; /*Расположение линий*/
int rq = 1;
int gq = 0;
int bq = 1;
int def = 0;
int deff = 0;
int re = 255;
int ge = 0;
int be =0;
int ae = 0;
int me = 0;
int GLOVESID=0;

  bool SEYTTGG,LLLDLDLDD=false;
	
int WEAPONSSFF=0;

int M9KNIFE =0;
int Butterflyy =0;
int Karambitt =0;
int jKommandoo =0;
int Flipp =0;
int Kunaii =0;
int Scorpionn =0;
int TANTOOO =0;



float SETFffffOVV = 240.0;
bool FOVG = false,DHDHDHDHDB,IREUEUEUEJ,BDBDSBXBDB;


float FGHGDFGHGG = 10.0;


JNIEXPORT void JNICALL
Java_androidx_appcompat_app_Main_Changes(
        JNIEnv *env,
        jobject activityObject,
        jint feature,
        jint value) {
    
			switch (feature) {
      case 1:
            chams = !chams;
            if (chams) {
           hexPatches.bypass.Modify();
				SetWallhack(true);
           
				
				} else {
            SetWallhack(false);
            }
            break;
   
            case 2:
            wireframe = !wireframe;
   if (wireframe) {
            SetWireframe(true);
            } else {
            SetWireframe(false);
            }
            break;
   
            case 3:
            glow = !glow;
   if (glow) {
            SetGlow(true);
            } else {
            SetGlow(false);
            }
            break;
   
   case 4:
            shading = !shading;
   if (shading) {
            SetShading(true);
            } else {
            SetShading(false);
            }
            break;
   
      case 5:
            outline = !outline;
   if (outline) {
            SetOutline(true);
            } else {
            SetOutline(false);
            }
            break;
   
            case 6:
            rainbow = !rainbow;
   if (rainbow) {
            SetRainbow(true);
         SetRainbow1(true);
            } else {
            SetRainbow(false);
   SetRainbow1(false);
            }
            break;
   
            case 8:
            SetR(value);
            break;
   
         case 9:
            SetG(value);
            break;
   
      case 10:
            SetB(value);
            break;
   
      case 11:
            SetOutlineWidth(value);
            break;
   
   case 12:
   SetWireframeWidth(value);
   break; 
            

   
   case 14:
	   SEYTTGG=!SEYTTGG;
	   break;
   
   case 15:
	   M9KNIFE=value;
	   break;
	   
	  case 16:
	   Butterflyy=value;
	   break; 
   
   case 17:
	   Karambitt=value;
	   break;
	   
	   case 18:
	   jKommandoo=value;
	   break;
	   
	   case 19:
	   Flipp=value;
	   break;
	   
	   case 20:
	   Kunaii=value;
	   break;
	   
	   case 21:
	   Scorpionn=value;
	   break;
	   
	   case 22:
	   TANTOOO=value;
	   break;
	
	   
	   case 24:
	   SEYTTGG=!SEYTTGG;
	   break;
   
   case 25:
	   WEAPONSSFF=value;
	   break;
	   
	   
	   
   case 27:
			 GLODDDDD =!GLODDDDD;
			 break;
		 
		case 28:
				GLOVESID = value;
				break;
				
			

	
			
			
			
			
			
			
			

			
			
			
			
	////Player Menu		
			case 30:
            GODMOD = !GODMOD;
            break;
        case 31:
            FIRE = !FIRE;
            break;
        case 32:
            FRIDE = !FRIDE;
            if(FRIDE){
				hexPatches.nn.Modify();
				}else{
					hexPatches.nn.Restore();
				}
				break;
	
        case 33:
            JUMPHACK = !JUMPHACK;
            break;
        case 34:
            DROP = !DROP;
            break;
      
case 35:
            RADAR = !RADAR;
            break;
        case 36:
            AMMO = !AMMO;
            break;

  case 37:
			ch1 = !ch1;
			if(ch1){
				hexPatches.shot.Modify();
				}else{
		        hexPatches.shot.Restore();
				}
				break;
				
				case 38:
			ch2 = !ch2;
			if(ch2){
				hexPatches.recoil.Modify();
				}else{
					hexPatches.recoil.Restore();
				}
				break;
			
			
				
			
			
				
				case 40:
            ESP2 = !ESP2;
            if(ESP2){
                //MakeToast(env, obj, OBFUSCATE("Esp On"), Toast::LENGTH_SHORT);
                ESPBoxStyle = 1;
               // color = Color::Green(255);
            }else{
             ///   MakeToast(env, obj, OBFUSCATE("Esp OFF"), Toast::LENGTH_SHORT);
            }
            break;


        case 41:
            ESPLine = !ESPLine;
            break;


        case 42:
            ESPBox = !ESPBox;
            break;
        
			case 43:
	        ESPDistance = !ESPDistance;
		    break;
	    
			case 44:
	      //  ESPHealth = !ESPHealth;
		    break;

			case 45:
            ESPRGB = !ESPRGB;
            break;
			
			
			
			case 46:
                if (value == 0) {
                    color = Color::White();

                } else if (value == 1) {
                    color = Color::Green();

                } else if (value == 2) {
                    color = Color::Blue();

                } else if (value == 3) {
                    color = Color::Red();

                } else if (value == 4) {
                    color = Color::Black();

                } else if (value == 5) {
                    color = Color::Yellow();

                } else if (value == 6) {
                    color = Color::Cyan();

                } else if (value == 7) {
                    color = Color::Magenta();

             
                }
            break;
            
            case 47:
            upval = value;
            break;
            
            case 48:
            upval2 = value;
            break;
            
            case 49:
            upval3 = value;
            break;
	
				
			
			
				
					
					case 51:
            aim = !aim;
            break;
			case 52:
            if (value > 0) {
                AimFov = value;
            }
            break;
					
			
			case 53:
					headsilent = !headsilent;
					break;
					
					
					case 54:
					bodysilent = !bodysilent;
					break;
			
			
					case 57:
			telekill =!telekill;
			break;	
			
			case 58:
			masskill =!masskill;
			break;	
			
			case 59:
				XXX = !XXX;
				break;
				
				case 60:
					SDDD = value;
					break;
				
			
				
				case 61:
			xbdbdhxxhxh = !xbdbdhxxhxh;
			if(xbdbdhxxhxh){
				hexPatches.antiflash1.Modify();
				hexPatches.antiflash2.Modify();
				hexPatches.antiflash3.Modify();
				}else{
					hexPatches.antiflash1.Restore();
				hexPatches.antiflash2.Restore();
					hexPatches.antiflash3.Restore();
					
					}
				break;
			
				
				case 62:
					NUCKI = !NUCKI;
					break;
				
					
					case 63:
					ENEMYNUCKI = !ENEMYNUCKI;
					break;
			case 64:
					FLASH777 = !FLASH777;
					break;
					
					
					case 65:
					GHK = !GHK;
					break;
				
						
					
					
					
					

				
					case 66:
					DDDHDJDJ = !DDDHDJDJ;
					if(DDDHDJDJ){
					hexPatches.DONT.Modify();
				}else{
					hexPatches.DONT.Restore();
				}
				break;
				
				case 67:
					SHSBSNSB = !SHSBSNSB;
					if(SHSBSNSB){
					hexPatches.MOVE.Modify();
				}else{
					hexPatches.MOVE.Restore();
				}
				break;
				
				
				case 68:
					LLPFOFFFK = !LLPFOFFFK;
					if(LLPFOFFFK){
					hexPatches.GRA.Modify();
				}else{
					hexPatches.GRA.Restore();
				}
				break;
					
					
              case 69:
					BDBDSBXBDB = !BDBDSBXBDB;
					if(BDBDSBXBDB){
					hexPatches.MONEY.Modify();
				}else{
					hexPatches.MONEY.Restore();
				}
				break;
				
				case 70:
				IREUEUEUEJ=!IREUEUEUEJ;
					break;
				
					
                case 71:
				DHDHDHDHDB=!DHDHDHDHDB;
				break;



	case 72:
				LLLDLDLDD=!LLLDLDLDD;
				if(LLLDLDLDD){
					hexPatches.fast1.Modify();
					hexPatches.fast2.Modify();
					hexPatches.fast3.Modify();
				}else{
					hexPatches.fast1.Restore();
					hexPatches.fast2.Restore();
					hexPatches.fast3.Restore();
					
				}
				break;
				
					
                case 73:
				DEFUS=!DEFUS;
				break;
					
			case 74:
				PLANT=!PLANT;
				break;
					
                case 75:
				FAST=!FAST;
				break;	
				
				case 76:
					handspos=!handspos;
					break;
				
				case 77:
					X1=value;
					break;
					case 78:
					Y1=value;
					break;
					
					case 79:
					Z1=value;
					break;
					
					
					
					}	
    }




JNIEXPORT jstring JNICALL
Java_androidx_appcompat_app_Menu_SliderString(
        JNIEnv *env,
        jobject clazz, jint feature, jint value) {
    // You must count your features from 0, not 1
    const char *SliderStr;
    if (feature == 6000) {
        switch (value) {
            case 0:
                SliderStr = "";
                break;
            case 1:
                SliderStr = "2x";
                break;
            case 2:
                SliderStr = "4x";
                break;
            case 3:
                SliderStr = "8x";
                break;
            case 4:
                SliderStr = "12x";
                break;
            case 5:
                SliderStr = "24x";
                break;
        }
        return env->NewStringUTF(SliderStr);
    }
    if (feature == 7000) {
        switch (value) {
            case 0:
                SliderStr = "Neck";
                break;
            case 1:
                SliderStr = "Hip";
                break;
            case 2:
                SliderStr = "Head";
                break;
        }
        return env->NewStringUTF(SliderStr);
    }
    if (feature == 8000) {
        if (value <= 015){
            SliderStr = "Low";
        }
        else if (value >= 15 && value <= 35){
            SliderStr = "Medium";
        }
        else if (value >= 35){
            SliderStr = "High";
        }
        return env->NewStringUTF(SliderStr);
    }
    return env->NewStringUTF(NULL);
}
}
// ---------- Hooking ---------- //

float SqrMagnitude(Vector3 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

float Magnitude(Vector3 v)
{
    return sqrt(SqrMagnitude(v));
}
float Distancebyirc(Vector3 a, Vector3 b)
{
    Vector3 end = {a.x - b.x, a.y - b.y, a.z - b.z};
    return Magnitude(end);
}

//////////





/**Entity_Manager**/
class ESPManager {
public:
    std::vector<enemy_t *> *enemies;

    ESPManager() {
        enemies = new std::vector<enemy_t *>();
    }

    bool isEnemyPresent(void *enemyObject) {
        for (std::vector<enemy_t *>::iterator it = enemies->begin(); it != enemies->end(); it++) {
            if ((*it)->object == enemyObject) {
                return true;
            }
        }

        return false;
    }

    void removeEnemy(enemy_t *enemy) {
        for (int i = 0; i < enemies->size(); i++) {
            if ((*enemies)[i] == enemy) {
                enemies->erase(enemies->begin() + i);

                return;
            }
        }
    }

    void tryAddEnemy(void *enemyObject) {
        if (isEnemyPresent(enemyObject)) {
            return;
        }

      // if (isPlayerDead(enemyObject)) {
          // return;
    //   }

        enemy_t *newEnemy = new enemy_t();

        newEnemy->object = enemyObject;

        enemies->push_back(newEnemy);
    }

    void updateEnemies(void *enemyObject) {
        for (int i = 0; i < enemies->size(); i++) {
            enemy_t *current = (*enemies)[i];

         //  if (isPlayerDead(current->object)) {
           //   enemies->erase(enemies->begin() + i);
         //   }

            if ((GetPlayerTeam(myPlayer) == GetPlayerTeam(current->object))) {
                enemies->erase(enemies->begin() + i);
            }
        }
    }

    void removeEnemyGivenObject(void *enemyObject) {
        for (int i = 0; i < enemies->size(); i++) {
            if ((*enemies)[i]->object == enemyObject) {
                enemies->erase(enemies->begin() + i);

                return;
            }
        }
    }

};

ESPManager *espManager;

Color GetPlayerColor(void *Player) {
    int MyTeam = GetPlayerTeam(myPlayer);
    int TeamNum = GetPlayerTeam(Player);
    Color color;

    if (MyTeam != TeamNum) {
        color = Color(235, 50, 0, 100);
    } else {
        color = Color(15, 110, 220, 100);
    }


    return color;
}


float NormalizeAngle (float angle){
    while (angle>360)
        angle -= 360;
    while (angle<0)
        angle += 360;
    return angle;
}

Vector3 NormalizeAngles (Vector3 angles){
    angles.x = NormalizeAngle (angles.x);
    angles.y = NormalizeAngle (angles.y);
    angles.z = NormalizeAngle (angles.z);
    return angles;
}

Vector3 ToEulerRad(Quaternion q1){
    float Rad2Deg = 360.0f / (M_PI * 2.0f);

    float sqw = q1.w * q1.w;
    float sqx = q1.x * q1.x;
    float sqy = q1.y * q1.y;
    float sqz = q1.z * q1.z;
    float unit = sqx + sqy + sqz + sqw;
    float test = q1.x * q1.w - q1.y * q1.z;
    Vector3 v;

    if (test>0.4995f*unit) {
        v.y = 2.0f * atan2f (q1.y, q1.x);
        v.x = M_PI / 2.0f;
        v.z = 0;
        return NormalizeAngles(v * Rad2Deg);
    }
    if (test<-0.4995f*unit) {
        v.y = -2.0f * atan2f (q1.y, q1.x);
        v.x = -M_PI / 2.0f;
        v.z = 0;
        return NormalizeAngles (v * Rad2Deg);
    }
    Quaternion q(q1.w, q1.z, q1.x, q1.y);
    v.y = atan2f (2.0f * q.x * q.w + 2.0f * q.y * q.z, 1 - 2.0f * (q.z * q.z + q.w * q.w)); // yaw
    v.x = asinf (2.0f * (q.x * q.z - q.w * q.y)); // pitch
    v.z = atan2f (2.0f * q.x * q.y + 2.0f * q.z * q.w, 1 - 2.0f * (q.y * q.y + q.z * q.z)); // roll
    return NormalizeAngles (v * Rad2Deg);
}
			

static void *get_aim(void *player) {
    return *(void **)((uint64_t) player + 0x2C);
}


bool IsPlayerDead(void *player) {
    if(GetPlayerHealthforclear(player) < 1) {
        return true;
    }
    return false;
}



















void *GetClosestEnemy(void *local) {
    if(!local) {
        return NULL;
    }

    float shortestDistance = 99999999.0f;
    float maxAngle = AimFov;

    void* closestEnemy = NULL;
    void* LocalPlayer = local;

    if(LocalPlayer != NULL) {

        for (int i = 0; i < espManager->enemies->size(); i++) {
            void *Player = (*espManager->enemies)[i]->object;

            if(Player != NULL && !IsPlayerDead(Player)) {

                Vector3 PlayerPos = GetPlayerLocation(Player);
                Vector3 LocalPlayerPos = GetPlayerLocation(LocalPlayer);

                if(true) {
                    Vector3 targetDir = Vector3::Normalized(PlayerPos - LocalPlayerPos);
                    float angle = Vector3::Angle(targetDir, get_forward(get_transform(get_camera()))) * 100.0;

                    if(angle <= maxAngle) {
                        if(angle < shortestDistance) {
                            shortestDistance = angle;
                            closestEnemy = Player;
                        }
                    }
                } else {
                    if(maxAngle < shortestDistance) {
                        shortestDistance = maxAngle;
                        closestEnemy = Player;
                    }
                }
            }
        }
    }
    return closestEnemy;
}

void *photon2 = NULL;
void *photon3 = NULL;

void (*SETID)(void* _this, monoString*);
void (*CLANTAG)(void* _this, monoString*);
void (*CLANTAG2)(void* _this, monoString*);



void (*MEDAL)(void* _this, int lol);
void (*MONEYSSS)(void* _this, int lol);

void (*MMRAAA)(void* _this, int lol);
void (*MMRAAA2)(void* _this, int lol);








void(*SetHealth)(void*, int lol);
Quaternion PlayerLook;
void *enemyPlayer = NULL;
Quaternion lookRotation;
Vector3 AimPlayerPos;
bool IsFiring;
void *closestEnemy2 = nullptr;
void (*Player_update)(void *player);
void _Player_update(void *player) {
    if (player != NULL) {
         Player_update(player);
		if (IsLocal(player)) {
            myPlayer = player;
         
		photon2 = get_photon(myPlayer);	
			
			
			
		
		
		
			
			
			
			
			///MONEYSSS(photon2,999999);
			
			
			
			// TESTHOOK(999,get_photon);
        if (handspos) {
                *(Vector3 *)((uint64_t) get_arms(myPlayer) + 0x94) = Vector3(X1 / 50, Y1 / 50, Z1 / 50);
                *(bool *)((uint64_t) get_arms(myPlayer) + 0x44) = false;
            }
        }

        if (myPlayer) {
        if (GetPlayerTeam(myPlayer) != GetPlayerTeam(player)) {
            enemyPlayer = player;
      
			
			
			
			} else if(IREUEUEUEJ){
                SETID(photon2, CreateMonoString(OBFUSCATE("<color=BLUE>7777777</color>")));
                IREUEUEUEJ = false;
			
				} else if(DHDHDHDHDB){
				CLANTAG(photon2, CreateMonoString(OBFUSCATE("<color=RED>t.me/pashazi</color>")));
                CLANTAG2(photon2,CreateMonoString(OBFUSCATE("<color=RED>t.me/pashazi</color>")));
                DHDHDHDHDB = false;
			
			   
			}
        }
  
   

    if (enemyPlayer) {

        if (telekill) {
            Vector3 enemyLocation = GetPlayerLocation(enemyPlayer);

            set_position(get_transform(myPlayer),
                         Vector3(enemyLocation.x, enemyLocation.y,
                                 enemyLocation.z - 1));
        }

 
 if(enemyPlayer){
   if (aim) {
      
    void* aimingdata = *(void **)((uint64_t) get_aim(myPlayer) + 0x5C);
                if (aimingdata) {
                    Vector3 angle = ToEulerRad(PlayerLook);
                    if (angle.x >= 275.0f)
                        angle.x -= 360.0f;
                    if (angle.x <= -275.0f)
                        angle.x += 360.0f;
                    *(Vector3 *)((uint64_t)aimingdata + 0x10) = angle;
                    *(Vector3 *)((uint64_t)aimingdata + 0x1C) = angle;
       
  } else {
        enemyPlayer = NULL;
        return;
					
					}   
      
 
	  
	
		
		if(aim){
     PlayerLook = Quaternion::LookRotation((GetPlayerLocation(closestEnemy2) + Vector3(0, -0.40f, 0)) - GetPlayerLocation(myPlayer), Vector3(0, 1, 0));
    }  
 
 
   
 
    Player_update(player);
 }
} 
}

        if(ESPRGB){
            if (re == 255){
                if (be == 0 ){
                    if (ge == 255){}
                    else{
                        ge = ge+1;
                    }
                }
            }
            if (ge == 255){
                if (re == 0){} else{
                    re = re-1;
                }
            }
            if (ge == 255) {
                if (re == 0) {
                    if (be==255){} else{
                        be = be+1;
                    }
                }
            }
            if (be == 255) {
                if (ge == 0) {
                    me = 1;
                    re = re+1;
                }
                else{
                    ge = ge-1;
                }
            }
            if (me == 1){
                if (re == 255){
                    if (be == 0){} else{
                        be = be-1;
                    }
                }
            }
            color = Color(re, ge, be, 255);
        }

        if (ESP2) {
            if (IsLocal) {
                if (myPlayer) {
                    if ((GetPlayerTeam(myPlayer) != GetPlayerTeam(player) || ESPTeamminate && !IsPlayerDead(player))) {
                        espManager->tryAddEnemy(player);
                   }
                    espManager->updateEnemies(player);
                }
            }
        }
    }

}










     
	
enum IOJMGOFMEEE // TypeDefIndex: 5392
{
    
    jKommando = 73,
    KnifeBayonet = 71,
    KnifeButterfly = 75,
    KnifeKarambit = 72,
    KunaiKnife = 78,
    ScorpionKnife = 79,
    FlipKnife = 77,
    AKR = 44,
    AKR12 = 45,
    AWM = 51,
    Deagle = 15,
    FabM = 63,
    FAMAS = 48,
    FiveSeven = 17,
    FnFal = 49,
    M4 = 46,
    Bomb = 100,
    P90 = 35,
    USP = 12,
	GrenadeHE = 91,
	KnifeTanto = 80,
	G22 = 11,
	M40 = 52,
	M4A1 = 43,
	M60 = 64,
	P350 = 13,
	M16=47,
	
	};

void (*SendChat)(void *_this, IOJMGOFMEEE);
void (*old_MultiPlayerChat_Update)(void *instance);
void MultiPlayerChat_Update(void *instance) {
 if (instance != NULL) {
       if(SEYTTGG){
	} else if (WEAPONSSFF==1) {
      SendChat(instance, AWM);
   SEYTTGG=true;
      } else if (WEAPONSSFF==2) {
      SendChat(instance, AKR);
   SEYTTGG=true;
   } else if (WEAPONSSFF==3) {
      SendChat(instance, G22);
  SEYTTGG=true;
	  } else if (WEAPONSSFF==4) {
      SendChat(instance, FnFal);
 SEYTTGG=true;
	  } else if (WEAPONSSFF==5) {
      SendChat(instance, M40);
   SEYTTGG=true;
	  } else if (WEAPONSSFF==6) {
      SendChat(instance, Deagle);
  SEYTTGG=true;
	  } else if (WEAPONSSFF==7) {
      SendChat(instance, FiveSeven);
  SEYTTGG=true;
	  } else if (WEAPONSSFF==8) {
      SendChat(instance, M4A1);
  SEYTTGG=true;
	  } else if (WEAPONSSFF==9) {
      SendChat(instance, M4);
     SEYTTGG=true; 
	  } else if (WEAPONSSFF==10) {
      SendChat(instance, M60);
      SEYTTGG=true;
	  } else if (WEAPONSSFF==11) {
      SendChat(instance, USP);
  SEYTTGG=true;
	  } else if (WEAPONSSFF==12) {
      SendChat(instance, P350);
	SEYTTGG=true;		
	
	 } else if (WEAPONSSFF==13) {
      SendChat(instance, AKR);
	SEYTTGG=true;	
	
		 } else if (WEAPONSSFF==14) {
      SendChat(instance, AWM);
	SEYTTGG=true;	
	
		 } else if (WEAPONSSFF==15) {
      SendChat(instance, AWM);
	SEYTTGG=true;	
	
		 } else if (WEAPONSSFF==16) {
      SendChat(instance, AWM);
	SEYTTGG=true;	
	
	
		 } else if (WEAPONSSFF==17) {
      SendChat(instance, AWM);
	SEYTTGG=true;	
	
	 } else if (WEAPONSSFF==18) {
      SendChat(instance, M4);
	SEYTTGG=true;	
	
		 } else if (WEAPONSSFF==19) {
      SendChat(instance, M4);
	SEYTTGG=true;
	
	 } else if (WEAPONSSFF==20) {
      SendChat(instance, M4);
	SEYTTGG=true;
	
	} else if (WEAPONSSFF==21) {
      SendChat(instance, M16);
	SEYTTGG=true;
	
	} else if (WEAPONSSFF==22) {
      SendChat(instance, M16);
	SEYTTGG=true;
	
	} else if (WEAPONSSFF==23) {
      SendChat(instance, P90);
	SEYTTGG=true;
	
	
	
	} else if (WEAPONSSFF==24) {
		  SendChat(instance, Bomb);
	SEYTTGG=true;
	       
	
	
	
	
	
	
	} else if (M9KNIFE==1) {
            SendChat(instance, KnifeBayonet);
         
			} else if (M9KNIFE==2) {
            SendChat(instance, KnifeBayonet);
          
			} else if (M9KNIFE==3) {
            SendChat(instance, KnifeBayonet);
            
			} else if (M9KNIFE==4) {
            SendChat(instance, KnifeBayonet);
            
			} else if (M9KNIFE==5) {
            SendChat(instance, KnifeBayonet);
            
			} else if (M9KNIFE==6) {
            SendChat(instance, KnifeBayonet);
            
			
			
			} else if (Butterflyy==1) {
            SendChat(instance, KnifeButterfly);
            
			} else if (Butterflyy==2) {
            SendChat(instance, KnifeButterfly);
           
			} else if (Butterflyy==3) {
            SendChat(instance, KnifeButterfly);
           
			} else if (Butterflyy==4) {
            SendChat(instance, KnifeButterfly);
            
			} else if (Butterflyy==5) {
            SendChat(instance, KnifeButterfly);
           
			} else if (Butterflyy==6) {
            SendChat(instance, KnifeButterfly);
            
		    
			
			} else if (Karambitt==1) {
            SendChat(instance, KnifeKarambit);
           
			} else if (Karambitt==2) {
            SendChat(instance, KnifeKarambit);
            
			} else if (Karambitt==3) {
            SendChat(instance, KnifeKarambit);
            
			} else if (Karambitt==4) {
            SendChat(instance, KnifeKarambit);
           
			} else if (Karambitt==5) {
            SendChat(instance, KnifeKarambit);
            
			} else if (Karambitt==6) {
            SendChat(instance, KnifeKarambit);
            
			} else if (Karambitt==7) {
            SendChat(instance, KnifeKarambit);
            
			} else if (Karambitt==8) {
            SendChat(instance, KnifeKarambit);
            
			
			
			} else if (jKommandoo==1) {
            SendChat(instance, jKommando);
            
			} else if (jKommandoo==2) {
            SendChat(instance, jKommando);
            
			} else if (jKommandoo==3) {
            SendChat(instance, jKommando);
            
			} else if (jKommandoo==4) {
            SendChat(instance, jKommando);
            
			} else if (jKommandoo==5) {
            SendChat(instance, jKommando);
            
            
			
			} else if (Flipp==1) {
            SendChat(instance, FlipKnife);
			
			} else if (Flipp==2) {
            SendChat(instance, FlipKnife);
			
			} else if (Flipp==3) {
            SendChat(instance, FlipKnife);
			
			} else if (Flipp==4) {
            SendChat(instance, FlipKnife);
			
			} else if (Flipp==5) {
            SendChat(instance, FlipKnife);
			
			} else if (Flipp==6) {
            SendChat(instance, FlipKnife);
			
            
			
			} else if (Kunaii==1) {
            SendChat(instance, KunaiKnife);
			
			} else if (Kunaii==2) {
            SendChat(instance, KunaiKnife);
			
			} else if (Kunaii==3) {
            SendChat(instance, KunaiKnife);
			
			} else if (Kunaii==4) {
            SendChat(instance, KunaiKnife);
			
			} else if (Kunaii==5) {
            SendChat(instance, KunaiKnife);
			
			} else if (Kunaii==6) {
            SendChat(instance, KunaiKnife);
			
            } else if (Kunaii==7) {
            SendChat(instance, KunaiKnife);
			
			
			} else if (Scorpionn==1) {
            SendChat(instance, ScorpionKnife);
		
			} else if (Scorpionn==2) {
            SendChat(instance, ScorpionKnife);
			
			} else if (Scorpionn==3) {
            SendChat(instance, ScorpionKnife);
			
			} else if (Scorpionn==4) {
            SendChat(instance, ScorpionKnife);
			
			} else if (Scorpionn==5) {
            SendChat(instance, ScorpionKnife);      
			
            
			
			} else if (TANTOOO==1) {
            SendChat(instance, KnifeTanto);
			
			} else if (TANTOOO==2) {
            SendChat(instance, KnifeTanto);
			
			} else if (TANTOOO==3) {
            SendChat(instance, KnifeTanto);
			
			} else if (TANTOOO==4) {
            SendChat(instance, KnifeTanto);
			
			} else if (TANTOOO==5) {
            SendChat(instance, KnifeTanto);
			
            } else if (TANTOOO==6) {
            SendChat(instance, KnifeTanto);
			
			
			
        old_MultiPlayerChat_Update(instance);
    }
  old_MultiPlayerChat_Update(instance);

}
}

void (*old_skins)(void *instance, int lol2, int lol3);
void skins(void *instance, int lol2, int lol3) {
    if (instance != NULL) {
          
		if (WEAPONSSFF==1) {
            lol3 = 51006;
       
			} else if (WEAPONSSFF==2) {
		    lol3 = 44002;
			
		    } else if (WEAPONSSFF==3) {
		    lol3 = 71103;
        
		    } else if (WEAPONSSFF==4) {
		    lol3 = 44901;
       
		    } else if (WEAPONSSFF==5) {
		    lol3 = 65201;
        
		    } else if (WEAPONSSFF==6) {
		    lol3 = 41502;
       
		    } else if (WEAPONSSFF==7) {
		    lol3 = 51701;
        
		    } else if (WEAPONSSFF==8) {
		    lol3 = 124300;
        
		    } else if (WEAPONSSFF==9) {
		    lol3 = 44603;
        
		    } else if (WEAPONSSFF==10) {
		    lol3 = 136400;
       
		    } else if (WEAPONSSFF==11) {
		    lol3 = 81200;
      
		    } else if (WEAPONSSFF==12) {
		    lol3 = 81300;

               } else if (WEAPONSSFF==13) {
		    lol3 = 44007;

 } else if (WEAPONSSFF==14) {
		    lol3 = 51008;

        } else if (WEAPONSSFF==15) {
		    lol3 = 51008;

		  } else if (WEAPONSSFF==16) {
		    lol3 = 85104;

        } else if (WEAPONSSFF==17) {
		    lol3 = 51001;

 } else if (WEAPONSSFF==18) {
		    lol3 = 46001;

		 } else if (WEAPONSSFF==19) {
		    lol3 = 46002;

 } else if (WEAPONSSFF==20) {
		    lol3 = 84624;

 } else if (WEAPONSSFF==21) {
		    lol3 = 104700;

} else if (WEAPONSSFF==22) {
		    lol3 = 47002;

} else if (WEAPONSSFF==23) {
		    lol3 = 83512;



			} else if (M9KNIFE==1) {
            lol3 = 71005;
			} else if (M9KNIFE==2) {
            lol3 = 71004;
			} else if (M9KNIFE==3) {
            lol3 = 71002;
			} else if (M9KNIFE==4) {
            lol3 = 97100;
			} else if (M9KNIFE==5) {
            lol3 = 71003;
			} else if (M9KNIFE==6) {
            lol3 = 71001;
			
			} else if (Butterflyy==1) {
            lol3 = 157500;
			} else if (Butterflyy==2) {
            lol3 = 47502;
			} else if (Butterflyy==3) {
            lol3 = 47503;
			} else if (Butterflyy==4) {
            lol3 = 97500;
			} else if (Butterflyy==5) {
            lol3 = 47505;
            } else if (Butterflyy==6) {
            lol3 = 57501;
			
			} else if (Karambitt==1) {
            lol3 = 72003;
			} else if (Karambitt==2) {
            lol3 = 72002;
			} else if (Karambitt==3) {
            lol3 = 72004;
			} else if (Karambitt==4) {
            lol3 = 72006;
			} else if (Karambitt==5) {
            lol3 = 72007;
			} else if (Karambitt==6) {
            lol3 = 72003;
			} else if (Karambitt==7) {
            lol3 = 97200;
			} else if (Karambitt==8) {
            lol3 = 97100;
            
            } else if (jKommandoo==1) {
            lol3 = 73006;
		    } else if (jKommandoo==2) {
            lol3 = 73003;
            } else if (jKommandoo==3) {
            lol3 = 73004;
            } else if (jKommandoo==4) {
            lol3 = 73002;
            } else if (jKommandoo==5) {
            lol3 = 97300;

            } else if (Flipp==1) {
            lol3 = 97700;
            } else if (Flipp==2) {
            lol3 = 97701;
             } else if (Flipp==3) {
            lol3 = 97702;
             } else if (Flipp==4) {
            lol3 = 97703;
             } else if (Flipp==5) {
            lol3 = 97704;
             } else if (Flipp==6) {
            lol3 = 97705;
            
             } else if (Kunaii==1) {
            lol3 = 77815;
            } else if (Kunaii==2) {
            lol3 = 77814;
            } else if (Kunaii==3) {
            lol3 = 77813;
            } else if (Kunaii==4) {
            lol3 = 77817;
            } else if (Kunaii==5) {
            lol3 = 77816;
            } else if (Kunaii==6) {
            lol3 = 97800;
            } else if (Kunaii==7) {
            lol3 = 97801;
            
             } else if (Scorpionn==1) {
            lol3 = 87921;
             } else if (Scorpionn==2) {
            lol3 = 87919;
             } else if (Scorpionn==3) {
            lol3 = 87920;
             } else if (Scorpionn==4) {
            lol3 = 87922;
             } else if (Scorpionn==5) {
            lol3 = 97900;
            
             } else if (TANTOOO==1) {
            lol3 = 138000;
             } else if (TANTOOO==2) {
            lol3 = 138001;
             } else if (TANTOOO==3) {
            lol3 = 138002;
             } else if (TANTOOO==4) {
            lol3 = 138003;
             } else if (TANTOOO==5) {
            lol3 = 138004;
             } else if (TANTOOO==6) {
            lol3 = 138005;

}
    }

    old_skins(instance, lol2, lol3);
}






void (*old_instantiate)(void *instance, int godhealth2, int godarmor2, bool godhasass2,
                        bool godisgod2,
                        float godsduration2);
void instantiate(void *instance, int godhealth2, int godarmor2, bool godhasass2,
                 bool godisgod2,
                 float godsduration2) {
    if (instance != NULL) {
        if (GODMOD) {
            godisgod2 = true;
            godsduration2 = 9999.0f;
        }
    }

    old_instantiate(instance, godhealth2, godarmor2, godhasass2, godisgod2,
                    godsduration2);
}


void (*StartDefuse)(void* _this, float defdist);
void (*old_bombmanager)(void *instance);
void bombmanager(void *instance) {
    if (instance != NULL) {
        
        if (DEFUS) {
            StartDefuse(instance, 9999.0f);
           DEFUS = false;
        }
    }
    old_bombmanager(instance);
}






/////PLANT HACK
bool (*old_pl1)(void *instance);
bool pl1(void *instance) {
    if (PLANT) {
        return true;
    }
    return old_pl1(instance);
}
bool (*old_pl2)(void *instance);
bool pl2(void *instance) {
    if (PLANT) {
        return true;
    }
    return old_pl2(instance);
}



////Fire
float (*old_FireRate)(void *instance);
float FireRate(void *instance) {
    if (instance != NULL && FIRE) {
        return 2.000f;
    }
    return old_FireRate(instance);
}


///////////////////////////////////drop knife////////////////////
bool (*old_DropKnife)(void *instance);
bool DropKnife(void *instance) {
    if (DROP) {
        return true;
    }
    return old_DropKnife(instance);
}

////Fast
float (*old_fast)(void *instance);
float fast(void *instance) {
    if (instance != NULL && FAST) {
        return 0.0f;
    }
    return old_fast(instance);
}



///////////////////////////////////drop knife////////////////////
bool (*old_R)(void *instance);
bool R(void *instance) {
    if (RADAR) {
        return true;
    }
    return old_R(instance);
}
///////////////////////////////////Jump////////////////////
bool (*old_ja)(void *instance);
bool ja(void *instance) {
    if (JUMPHACK) {
        return true;
    }
    return old_ja(instance);
}

////Ammo
short (*old_am1)(void *instance);
short am1(void *instance) {
    if (instance != NULL && AMMO) {
        return 2000;
    }
    return old_am1(instance);
}

////Ammo
short (*old_am2)(void *instance);
short am2(void *instance) {
    if (instance != NULL && AMMO) {
        return 2000;
    }
    return old_am2(instance);
}
////Ammo
short (*old_am3)(void *instance);
short am3(void *instance) {
    if (instance != NULL && AMMO) {
        return 2000;
    }
    return old_am3(instance);
}
////Ammo
short (*old_am4)(void *instance);
short am4(void *instance) {
    if (instance != NULL && AMMO) {
        return 2000;
    }
    return old_am4(instance);
}







float (*old_speed)(void *instance);
float speed(void *instance) {
   if (instance != NULL) {
        if(XXX){
	   return 11;
   }
    return old_speed(instance);
}
}





    



//You need Vector3 struct
//Offsets are work in 0.15.10 Standoff 2 version







/*
void* (*old_NICKNAMEJSHSJSHS)(void *instance,monoString*lol);
void* NICKNAMEJSHSJSHS(void *instance,monoString*lol) {
   if (instance != NULL) {
        if(DDJDJDJDJDDH){
			NICKNAMEJSHSJSHS(instance,CreateMonoString(OBFUSCATE("<color=RED>Pasha Production</color>")));
			}
    return old_NICKNAMEJSHSJSHS(instance,lol);
}
}

*/

	




int(*old_setGloves)(void *instance);
int setGloves(void *instance) {
        if(GLODDDDD){
	    if (GLOVESID==1) {
            return 3000;
        } else if (GLOVESID==2) {
			return 3001;
		} else if (GLOVESID==3) {
			return 3002;
		} else if (GLOVESID==4) {
			return 3003;
		} else if (GLOVESID==5) {
			return 3004;
		} else if (GLOVESID==6) {
			return 3005;
		} else if (GLOVESID==7) {
			return 3006;
		} else if (GLOVESID==8) {
			return 3007;
		} else if (GLOVESID==9) {
			return 3008;
		} else if (GLOVESID==10) {
			return 3009;
		} else if (GLOVESID==11) {
			return 3010;	
		
		}
    return old_setGloves(instance);
}
}


void (*old_hitboxrage)(void* player, void* config, int test, float rag);
void hitboxrage(void* player, void* config, int test, float rag) {
    if (player != NULL) {
        if (headsilent) {
            *(float *)((uint64_t) config + 0x2C) = 9.56f;
        
			} else if (bodysilent) {
            *(float *)((uint64_t) config + 0x2C) = 0.5f;
        }
    }
    old_hitboxrage(player, config, test, rag);
}


	
	

		
	


	
	




void DrawESP(ESP esp, int screenWidth, int screenHeight) {
 if (ESP2) {
       closestEnemy2 = GetClosestEnemy(myPlayer);
            AimPlayerPos = WorldToScreenPoint(get_camera(),
                                             Vector3{GetPlayerLocation(closestEnemy2).x, GetPlayerLocation(closestEnemy2).y + 1.6f, GetPlayerLocation(closestEnemy2).z});;
	          
	 if (espManager->enemies->empty()) {
            return;
        }
      
		
		
		for (int i = 0; i < espManager->enemies->size(); i++) {
            void *Player = (*espManager->enemies)[i]->object;

            if (get_camera() != nullptr && Player != nullptr && !IsPlayerDead(Player)) {
                color.a = 255;


                Vector3 HeadPos = {GetPlayerLocation(Player).x, GetPlayerLocation(Player).y + 1.6f, GetPlayerLocation(Player).z};

                Vector3 RightShoulderPos = {GetPlayerLocation(Player).x,
                                            GetPlayerLocation(Player).y + 0.3f,
                                            GetPlayerLocation(Player).z};

                Vector3 LeftShoulderPos = {GetPlayerLocation(Player).x,
                                           GetPlayerLocation(Player).y + 0.3f,
                                           GetPlayerLocation(Player).z};

                Vector3 LeftShoulderPosX = {LeftShoulderPos.x - 0.4f, LeftShoulderPos.y - 2.0f,
                                            LeftShoulderPos.z};

                Vector3 RightShoulderPosX = {RightShoulderPos.x + 0.4f, RightShoulderPos.y - 2.0f,
                                             RightShoulderPos.z};

                Vector3 ToePos = {GetPlayerLocation(Player).x, GetPlayerLocation(Player).y -0.3f,GetPlayerLocation(Player).z};

                /**Getting the camera**/
                void *camera = get_camera();

                Vector3 HeadPosition = WorldToScreenPoint(camera, HeadPos);
                if (HeadPosition.z < 1.f) continue;

                Vector3 HombroD = WorldToScreenPoint(camera, RightShoulderPosX);
                if (HombroD.z < 1.f) continue;

                Vector3 HombroI = WorldToScreenPoint(camera, LeftShoulderPosX);
                if (HombroI.z < -1.f) continue;

                Vector3 PositionToe = WorldToScreenPoint(camera, ToePos);
                if (PositionToe.z < 1.f) continue;

                Vector3 End = HeadPosition;
                Vector3 End2 = PositionToe;

                float distance;

                distance = Distancebyirc(GetPlayerLocation(myPlayer), HeadPos);

                float Hight =
                        abs(HeadPosition.y - PositionToe.y) * (upval / upval2), Width =
                        Hight * 0.60f;

                Rect PlayerRect(HeadPosition.x - Width / 2.f,
                                    get_screen_height() - HeadPosition.y,
                                    Width, Hight);

                if (ESPLine) {
                    esp.DrawLine(color, upval3,
                                 Vector2((get_screen_width() / 2), 0),
                                 Vector2((get_screen_width() -
                                          (get_screen_width() - HeadPosition.x)),
                                         (get_screen_height() - HeadPosition.y)));
                    esp.DrawLine(color, upval3,
                                 Vector2(get_screen_width() / 2,
                                         get_screen_height() / 2),
                                 Vector2((get_screen_width() - (get_screen_width() -
                                                       AimPlayerPos.x)),
                                         (get_screen_height() -
                                                 AimPlayerPos.y)));

                }{}


                if (ESPBox) {
                    //esp.DrawBox(color, 2.0f, PlayerRect);
                    esp.DrawRect(color, 2.0f, Vector2(PlayerRect.x, PlayerRect.y), PlayerRect.w, PlayerRect.h );
                }

                if (ESPDistance) {
                    char buffer[30];
                    sprintf(buffer, "%.2fm", distance);
                    esp.DrawText(color, 0.6f, buffer,
                                 Vector2((PlayerRect.x + (PlayerRect.w / 2)),
                                         PlayerRect.y + PlayerRect.h + 21.5f), 24.0f);
                }

                if (ESPHealth) {
                    char bufferlife[30];
                    sprintf(bufferlife, "%d", GetPlayerHealth(Player));
                    Color clr = Color(0, 255, 0, 255);
                    Color colorh = Color(0, 0, 0, 155);
                    if (GetPlayerHealth(Player) <= 100) {
                        clr = Color::Green();
                    }
                    if (GetPlayerHealth(Player) <= 75) {
                        clr = Color::Naranja();
                    }
                    if (GetPlayerHealth(Player) <= 50) {
                        clr = Color::Red();
                    }
                    esp.DrawLine(colorh, 5, Vector2(PlayerRect.x + PlayerRect.w + 10, PlayerRect.y + PlayerRect.h),Vector2(PlayerRect.x + PlayerRect.w + 10, (PlayerRect.y + PlayerRect.h) - ((PlayerRect.h / 100) * 100)));
                    esp.DrawLine(clr, 5, Vector2(PlayerRect.x + PlayerRect.w + 10, PlayerRect.y + PlayerRect.h),Vector2(PlayerRect.x + PlayerRect.w + 10, (PlayerRect.y + PlayerRect.h) - ((PlayerRect.h / 100) * GetPlayerHealth(Player))));
                    esp.DrawText(Color::White(255), 15.0f , bufferlife, Vector2(PlayerRect.x + PlayerRect.w + 10, (PlayerRect.y + PlayerRect.h) - ((PlayerRect.h / 100) *GetPlayerHealth(Player))), 10);
                }
            }
            else {
                    espManager->removeEnemyGivenObject(Player);
                }
            }
        }
    }




void (*ThrowGrenade)(void *instance, int lollll, Vector55 position, Vector55 direction, float up, int type);
void (*old_GrenadeManager)(void *instance);
void GrenadeManager(void *instance) {
   if (NUCKI&& myPlayer) {
ThrowGrenade(instance, 91, GetPlayerLocation2(myPlayer), Vector55(0,0.25f,0), 0.0f, 0);
}
if(enemyPlayer){
if (ENEMYNUCKI) {
ThrowGrenade(instance, 91, GetPlayerLocation2(enemyPlayer),Vector55(0,0.25f,0),0.0f,0);
}
if(enemyPlayer){
if (FLASH777) {
 ThrowGrenade(instance, 93, GetPlayerLocation2(enemyPlayer),Vector55(0,0.25f,0),0.0f,0);
}
if(enemyPlayer){
if (GHK) {
ThrowGrenade(instance, 92, GetPlayerLocation2(enemyPlayer),Vector55(0,0.25f,0),0.0f,0);
}
	old_GrenadeManager(instance);
}}}}






float (*old_DJFHFHFFH)(void *instance);
float DJFHFHFFH(void *instance) {
   if (instance != NULL) {
        if(FOVG){
	   return SETFffffOVV;
   }
    return old_DJFHFHFFH(instance);
}
}


















 

 
/*Bypass*/
monoString *(*old_shit)(...);
monoString *shit(void *pmt1, void*pmt2) {

    monoString*valuer = old_shit(pmt1, pmt2);

  LOGI("%s", valuer->get_string().c_str());

    return valuer;
}



string byy, cock;
string anal = "";
string anal2 = "";
void* (*yugatuU)(void* asdhj, monoString* ashdasdg, uint fhshd);
void* AsdFAgh(void* qweyuhsa, monoString* sdfhkfdjkshfhdkj, uint fhshd) {
   if (qweyuhsa != NULL) {
    if (Auth) {
  //LOGD("arms called");
   string fmodstudio = OBFUSCATE("/libfmodstudio.so|");
   
   string fmod = OBFUSCATE("/libfmod.so|/data/media/0/Android/data/com.axlebolt.standoff2/files/il2cpp/Metadata/global-metadata.dat|/data/media/0/Android/data/com.axlebolt.standoff2/files/il2cpp/Metadata/libil2cpp.so|");
   
   string cpp = OBFUSCATE("/libil2cpp.so|");
   
   string unityyyy = OBFUSCATE("/libunity.so|");
   
   string main = OBFUSCATE("/libmain.so|/data/media/0/Android/data/com.axlebolt.standoff2/files/il2cpp/Resources/mscorlib.dll-resources.dat|");
   
   string ddddddddd = OBFUSCATE("/base.apk|");
   
   string directioihb = OBFUSCATE("/oat/arm/base.odex|");
   
   string ZNZXNXNXNZ = OBFUSCATE("/oat/arm/base.vdex");
   
   string SJJJJ =cock+fmodstudio+ cock +fmod+cock+cpp+cock+unityyyy+cock+main+ anal+ddddddddd+anal +directioihb+anal+ZNZXNXNXNZ;
   
   string nmsdfmsdf = sdfhkfdjkshfhdkj->get_string();
   
   string signature = OBFUSCATE("lcG7acvUIg0k4FQSQmAbyw1tN0o=");
  
   string hashhhgh = OBFUSCATE("base.apk:d5a8e89e973a0f4c4539f3c1d8867205:93707076|main.1060.com.axlebolt.standoff2.obb:596d06460add9c1300e07f97fee36761:1293715767");
   
   string FINDERRTT = OBFUSCATE("/libfmodstudio.so|");
   
   string RJDJDHDDB = OBFUSCATE("/lib/arm");
   
   string XNXNDJDJDJD = OBFUSCATE("/lib/arm");
   
   string PPPPPPPPO = OBFUSCATE("/base.apk");
   
   string FFJFFJFJFJFJ = OBFUSCATE("base.apk:");
   
   string IRRUTURURUR = OBFUSCATE("=");
    
       if (nmsdfmsdf.find(FINDERRTT) != std::string::npos){
       sdfhkfdjkshfhdkj = CreateMonoString(SJJJJ.c_str());
    
    } else if (nmsdfmsdf.find(RJDJDHDDB) != std::string::npos){
       cock = sdfhkfdjkshfhdkj->get_string();
       int s = cock.find(XNXNDJDJDJD);
       anal = cock.substr(0, s);
    
    } else  if (nmsdfmsdf.find(PPPPPPPPO) != std::string::npos) {
       byy = sdfhkfdjkshfhdkj->get_string();
    
    } else if(nmsdfmsdf.find(FFJFFJFJFJFJ) != std::string::npos) {
      sdfhkfdjkshfhdkj = CreateMonoString(hashhhgh.c_str());
    
    } else if(nmsdfmsdf.find(IRRUTURURUR) != std::string::npos) {
       sdfhkfdjkshfhdkj = CreateMonoString(signature.c_str());
   }
//  LOGI("%s", fucksuck->toChars());
 
 }
  
 return yugatuU(qweyuhsa, sdfhkfdjkshfhdkj, fhshd);

 

  }
}












void *HACK(void *) {
  //LOGI(OBFUSCATE("NEW LOAD V0 18 5"));
	ProcMap il2cppMap;
  do {
        il2cppMap = KittyMemory::getLibraryMap(libName);
        sleep(0);
 } while (!il2cppMap.isValid()&&mlovinit());
espManager = new ESPManager();
setShader("_BumpMap");    
LogShaders();
Wallhack();


/*

SETMASTER262626 = (bool (*)(void*)) getAbsoluteAddress("libil2cpp.so", 0x10B95A4);
SETMASTER2 = (bool (*)(void*)) getAbsoluteAddress("libil2cpp.so", 0x10C14F8);
SETMASTER3 = (bool (*)(void*)) getAbsoluteAddress("libil2cpp.so", 0x10B1BB0);
	
CLOSECONNECTED = (bool (*)(void*)) getAbsoluteAddress("libil2cpp.so", 0x10B1BB0);
	
	MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x10C0510")),
       (void *) NICKNAMEJSHSJSHS,
  (void **) &old_NICKNAMEJSHSJSHS);
	

*/




//MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xBC849C")),
               //   (void *) cmdd,
               //   (void **) &old_cock);
               














CLANTAG2 = (void (*)(void*, monoString*)) getAbsoluteAddress(libName,OBFUSCATEOFFSET("0xD94C5C"));
CLANTAG = (void (*)(void*, monoString*)) getAbsoluteAddress("libil2cpp.so", OBFUSCATEOFFSET("0xD94DF0"));
	

SETID = (void (*)(void*, monoString*)) getAbsoluteAddress("libil2cpp.so",OBFUSCATEOFFSET("0xD94AAC"));
	

	////BYPASSSSSSSSSS
 
	//TESTHOOK = (int (*)(void *)) getAbsoluteAddress("libil2cpp.so", 0xD936E0);//+
    			

     MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x90D970")),
       (void *) AsdFAgh,
     (void **) &yugatuU);
	
	
	
		
		
		
		
	//MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x90D788")),
    //(void *) shit,
     //  (void **) &old_shit);
         
         
    
    /////GrenadeManager         
ThrowGrenade = (void (*)(void*, int, Vector55, Vector55, float, int))getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xAE7AA0"));//

	
	
	
	
MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xAEB864")),
                  (void *) GrenadeManager,
                  (void **) &old_GrenadeManager);

		 
	
	   
			   
	
	
		  
		   
		   	//GLOVES     , Dictionary<Team,  
		     MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xA3ED6C")),
                (void *) setGloves,
                  (void **) &old_setGloves); 
		   
		   
		   
		   
		   
          ///     public class PlayerHitbox : MonoBehaviour //             
	MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xEEC080")),
               (void *) hitboxrage,
               (void **) &old_hitboxrage);
				  
				    
		 
	


	

hexPatches.bypass = MemoryPatch::createWithHex(libName,string2Offset(OBFUSCATE("0xDDC8D0")), OBFUSCATE("1E FF 2F E1"));//slot 64
	hexPatches.bypass.Modify();   
	
 hexPatches.shot = MemoryPatch::createWithHex(XD, string2Offset(OBFUSCATE("0x9EC7F8")),OBFUSCATE("003582C7"));//6F12833A3B030000

 hexPatches.recoil = MemoryPatch::createWithHex(XD,string2Offset(OBFUSCATE("0x27E56C")),OBFUSCATE("804FC347"));//0000B443DB0F4940B0B584B06D461446

    
 
 
 
 
	
	
	//FlashbangEffectController     [Address(RVA = "0xCEA4A8", Offset = "0xCEA4A8", VA = "0xCEA4A8", Slot = "13")]

	//public override void FCPNHNHHANO(Vector3 OJPGFNODLAK, PlayerController DIHGGAAABEE) { }
	
	
hexPatches.antiflash1 = MemoryPatch::createWithHex("libil2cpp.so", 0xAE5CF8, "1E FF 2F E1");


///GrenadeManager
///private bool BMBNFOIPPBO(DroppedGrenadeController PCNKEOJAGNA, Vector3 LCBMGJAAMHB) { }


hexPatches.GRA = MemoryPatch::createWithHex("libil2cpp.so", 0xaeac98, "1E FF 2F E1");




///gamecontroller
//public virtual int LDLECJHNLDA(InventoryParameters IJLEGBGDFOO) { }

hexPatches.MONEY = MemoryPatch::createWithHex("libil2cpp.so", 0x8B927C, "01 00 A0 E3 1E FF 2F E1");


hexPatches.DONT = MemoryPatch::createWithHex("libil2cpp.so", 0x8B6C80, "01 00 A0 E3 1E FF 2F E1");



	//////MS HOOK/////

   hexPatches.MOVE = MemoryPatch::createWithHex("libil2cpp.so", 0xF8CB20, "01 00 A0 E3 1E FF 2F E1");



	

   



///Axlebolt.Standoff.Player   0.18.3
/// PlayerController+
/// public void PELIMKLCDLK(int BIHDPEFNCBG, int DBGHIKMNIGN, bool AODDINOBCJL, bool JHKLDNKLICF, float HGCMJNFNHPF) { }
    MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xDE1554")),
                   (void *) instantiate,
                   (void **) &old_instantiate);




    //////////SET WEAPON
///WeaponController  public virtual void JJCFMHMCOEI(int KAGPFJJMLJA, EBAOHNPFNHJ JKCLOLCEELA) Slot 6
  //public abstract class WeaponController : MonoBehaviour //
	
	MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xD47434")), (void *) skins,
                  (void **) &old_skins);//+

/////Axlebolt.Standoff.Game
///Gamecontroller
  ///public abstract class GameController : PunBehaviour,
		
				 
  SendChat = (void (*)(void *, IOJMGOFMEEE)) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x8AE6E0"));//

    MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x8B9B94")),
                  (void *) MultiPlayerChat_Update,
                   (void **) &old_MultiPlayerChat_Update);

   




///Radarmanager  private bool OEJGLHADIAD(PhotonPlayer AFFEBDIILFO)

//return default(bool);
///}

  MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x8FB6A8")), (void *) R,
                 (void **) &old_R);

				   
				   
///KnifeController   slot 20
   MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xD432C8")), (void *) DropKnife,
                (void **) &old_DropKnife);

	
	
	////HitManager     public bool PGABBDOFJML(PhotonPlayer NHKGMFFGEDN, PhotonPlayer JCPKIOCKIGP)
   
		//hexPatches.nn = MemoryPatch::createWithHex("libil2cpp.so", 0x0, "01 00 A0 E3 1E FF 2F E1");		   
				   
   
//// get_FireRate
   MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xD3C670")), (void *) FireRate,
                   (void **) &old_FireRate);

   
				   
				   
	//// public class CharacterController : Collider //                    public bool get_isGrounded() { }
    MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x2507750")), (void *) ja,
                   (void **) &old_ja);

    MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x903454")), (void *) am1,
                   (void **) &old_am1);
    MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x90342C")), (void *) am2,
                  (void **) &old_am2);
 


    
				  
//////BOMB HACK   
    
    ///BombManager               public void PCIELKKEELB(float JPPJPOKJOJH, float APFMNBECGJH)
    
      
  StartDefuse = (void (*)(void*, float)) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xBEBE10"));

  
  
  MSHookFunction((void *) getAbsoluteAddress("libil2cpp.so", 0xBE9134), (void *) bombmanager, (void** ) &old_bombmanager);
     
  
 ///  <IsInBombSite>b__0(BombSite zone) { }
    MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xBED5EC")),
                   (void *) pl1,
                   (void** ) &old_pl1);

       
    ///   <IsInBombSite>b__0(BombSite zone) { }
    MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xBED668")),
                   (void *) pl2,
                   (void** ) &old_pl2);

    
 
 ////get_PlantDuration
 MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xBE6EA0")),
                  (void *) fast,
                 (void** ) &old_fast);			 
		
				 
		  		 
	//	private bool		 
hexPatches.fast1 = MemoryPatch::createWithHex(libName, string2Offset(OBFUSCATE("0xBEA0EC")), OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));
hexPatches.fast2 = MemoryPatch::createWithHex(libName, string2Offset(OBFUSCATE("0xBE9684")), OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));
hexPatches.fast3 = MemoryPatch::createWithHex(libName, string2Offset(OBFUSCATE("0xBE92AC")), OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));
//hexPatches.fast4 = MemoryPatch::createWithHex(libName, string2Offset(OBFUSCATE("0xBD06C4")), OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));
//hexPatches.fast5 = MemoryPatch::createWithHex(libName, string2Offset(OBFUSCATE("0xBD2818")), OBFUSCATE("01 00 A0 E3 1E FF 2F E1"));
				
				
///////get_SpeedDefault
			MSHookFunction((void *) getAbsoluteAddress(libName, OBFUSCATEOFFSET("0xDD6648")),
                  (void *) speed,
                 (void **) &old_speed);	  
			
			




			////UNITY 			   NEW 0 18 5F1
	MSHookFunction((void *) getAbsoluteAddress("libil2cpp.so", 0xDE0CA0), (void *) _Player_update,
                   (void **) &Player_update); //Player.Update(); Standoff 2 0.15.3 - 0x12B0A44
   

				   
	    IsLocal = (bool (*)(void *)) getAbsoluteAddress("libil2cpp.so", 0xDDEF5C);//+
    			   
	    GetPlayerTeam = (int (*)(void *)) getAbsoluteAddress("libil2cpp.so", 0xDDCA18);//+
   
	  ///  GetPlayerHealth = (int (*)(void *)) getAbsoluteAddress("libil2cpp.so",0xECD4D0);//0xED1F48  0xECFC00  0xECDC7C

	    GetPlayerHealthforclear = (int (*)(void *)) getAbsoluteAddress("libil2cpp.so",0xDDD4CC);//0xDDE108

   
				 
			get_transform2 = (void *(*)(void *))getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x1BC0800"));
    
    
           Transform_get_position2 = (void (*)(void *, Vector55 *))getAbsoluteAddress(libName, OBFUSCATEOFFSET("0x21E0224"));//+
	 

		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		   
		
		
		   
//////////// ANTIBAN

    hexPatches.antiban1 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBED88, "1E FF 2F E1");
    hexPatches.antiban2 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBE378, "1E FF 2F E1");
    hexPatches.antiban3 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBE7E4, "1E FF 2F E1");
    hexPatches.antiban4 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBF284, "1E FF 2F E1");
    hexPatches.antiban5 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBF42C, "1E FF 2F E1");
    hexPatches.antiban6 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBEE84, "1E FF 2F E1");
    hexPatches.antiban7 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBE010, "1E FF 2F E1");
    hexPatches.antiban8 = MemoryPatch::createWithHex("libil2cpp.so", 0x6692B4, "1E FF 2F E1");
    hexPatches.antiban9 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBEA50, "1E FF 2F E1");
    hexPatches.antiban10 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBDD58, "1E FF 2F E1");
////////////////////////////////////////////////////
    hexPatches.antiban11 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBE520, "1E FF 2F E1");
    hexPatches.antiban12 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBEFC8, "1E FF 2F E1");
    hexPatches.antiban13 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBE1EC, "1E FF 2F E1");
    hexPatches.antiban14 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBF570, "1E FF 2F E1");
    hexPatches.antiban15 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBEBC4, "1E FF 2F E1");
    hexPatches.antiban16 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBF0A8, "1E FF 2F E1");
    hexPatches.antiban17 = MemoryPatch::createWithHex("libil2cpp.so", 0xEC01B8, "1E FF 2F E1");
    hexPatches.antiban18 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBFFC8, "1E FF 2F E1");
    hexPatches.antiban19 = MemoryPatch::createWithHex("libil2cpp.so", 0xEC0094, "1E FF 2F E1");
    hexPatches.antiban20 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBFDF8, "1E FF 2F E1");
////////////////////////////////////////////////////
    hexPatches.antiban21 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBFB70, "1E FF 2F E1");
    hexPatches.antiban22 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBF9D4, "1E FF 2F E1");
    hexPatches.antiban23 = MemoryPatch::createWithHex("libil2cpp.so", 0xEBFD40, "1E FF 2F E1");
    hexPatches.antiban24 = MemoryPatch::createWithHex("libil2cpp.so", 0xEC01C0, "1E FF 2F E1");
    hexPatches.antiban25 = MemoryPatch::createWithHex("libil2cpp.so", 0xEC0404, "1E FF 2F E1");
    hexPatches.antiban26 = MemoryPatch::createWithHex("libil2cpp.so", 0xEC040C, "1E FF 2F E1");
    hexPatches.antiban27 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6168, "1E FF 2F E1");
    hexPatches.antiban28 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB5C3C, "1E FF 2F E1");
    hexPatches.antiban29 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6164, "1E FF 2F E1");
    hexPatches.antiban30 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6160, "1E FF 2F E1");
////////////////////////////////////////////////////
    hexPatches.antiban31 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB5C40, "1E FF 2F E1");
    hexPatches.antiban32 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB5EC0, "1E FF 2F E1");
    hexPatches.antiban33 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB615C, "1E FF 2F E1");
    hexPatches.antiban34 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6158, "1E FF 2F E1");
    hexPatches.antiban35 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB5C38, "1E FF 2F E1");
    hexPatches.antiban36 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB78E4, "1E FF 2F E1");
    hexPatches.antiban37 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6348, "1E FF 2F E1");
    hexPatches.antiban38 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6900, "1E FF 2F E1");
    hexPatches.antiban39 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6C94, "1E FF 2F E1");
    hexPatches.antiban40 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6170, "1E FF 2F E1");
////////////////////////////////////////////////////
    hexPatches.antiban41 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB7290, "1E FF 2F E1");
    hexPatches.antiban42 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6674, "1E FF 2F E1");
    hexPatches.antiban43 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6254, "1E FF 2F E1");
    hexPatches.antiban44 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB680C, "1E FF 2F E1");
    hexPatches.antiban45 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6428, "1E FF 2F E1");
    hexPatches.antiban46 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB764C, "1E FF 2F E1");
    hexPatches.antiban47 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB80D4, "1E FF 2F E1");
    hexPatches.antiban48 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB65C0, "1E FF 2F E1");
    hexPatches.antiban49 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB6174, "1E FF 2F E1");
    hexPatches.antiban50 = MemoryPatch::createWithHex("libil2cpp.so", 0x665684, "1E FF 2F E1");
////////////////////////////////////////////////////
    hexPatches.antiban51 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB7E9C, "1E FF 2F E1");
    hexPatches.antiban52 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB7A00, "1E FF 2F E1");
    hexPatches.antiban53 = MemoryPatch::createWithHex("libil2cpp.so", 0x6656F4, "1E FF 2F E1");
    hexPatches.antiban54 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB7004, "1E FF 2F E1");
    hexPatches.antiban55 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB71CC, "1E FF 2F E1");
    hexPatches.antiban56 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB7094, "1E FF 2F E1");
    hexPatches.antiban57 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB8378, "1E FF 2F E1");
    hexPatches.antiban58 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB7D64, "1E FF 2F E1");
    hexPatches.antiban59 = MemoryPatch::createWithHex("libil2cpp.so", 0xBB84B0, "1E FF 2F E1");



                hexPatches.antiban1.Modify();
                hexPatches.antiban2.Modify();
                hexPatches.antiban3.Modify();
                hexPatches.antiban4.Modify();
                hexPatches.antiban5.Modify();
                hexPatches.antiban6.Modify();
                hexPatches.antiban7.Modify();
                hexPatches.antiban8.Modify();
                hexPatches.antiban9.Modify();
                hexPatches.antiban10.Modify();
                hexPatches.antiban11.Modify();
                hexPatches.antiban12.Modify();
                hexPatches.antiban13.Modify();
                hexPatches.antiban14.Modify();
                hexPatches.antiban15.Modify();
                hexPatches.antiban16.Modify();
                hexPatches.antiban17.Modify();
                hexPatches.antiban18.Modify();
                hexPatches.antiban19.Modify();
                hexPatches.antiban20.Modify();
                hexPatches.antiban21.Modify();
                hexPatches.antiban22.Modify();
                hexPatches.antiban23.Modify();
                hexPatches.antiban24.Modify();
                hexPatches.antiban25.Modify();
                hexPatches.antiban26.Modify();
                hexPatches.antiban27.Modify();
                hexPatches.antiban28.Modify();
                hexPatches.antiban29.Modify();
                hexPatches.antiban30.Modify();
                hexPatches.antiban31.Modify();
                hexPatches.antiban32.Modify();
                hexPatches.antiban33.Modify();
                hexPatches.antiban34.Modify();
                hexPatches.antiban35.Modify();
                hexPatches.antiban36.Modify();
                hexPatches.antiban37.Modify();
                hexPatches.antiban38.Modify();
                hexPatches.antiban39.Modify();
                hexPatches.antiban40.Modify();
                hexPatches.antiban41.Modify();
                hexPatches.antiban42.Modify();
                hexPatches.antiban43.Modify();
                hexPatches.antiban44.Modify();
                hexPatches.antiban45.Modify();
                hexPatches.antiban46.Modify();
                hexPatches.antiban47.Modify();
                hexPatches.antiban48.Modify();
                hexPatches.antiban49.Modify();
                hexPatches.antiban50.Modify();
                hexPatches.antiban51.Modify();
                hexPatches.antiban52.Modify();
                hexPatches.antiban53.Modify();
                hexPatches.antiban54.Modify();
                hexPatches.antiban55.Modify();
                hexPatches.antiban56.Modify();
                hexPatches.antiban57.Modify();
                hexPatches.antiban58.Modify();
                hexPatches.antiban59.Modify();
                hexPatches.antiban60.Modify();
              		   
	
		
		
			
return NULL;
	
	

     }


 extern "C"
JNIEXPORT void JNICALL
Java_androidx_appcompat_app_Menu_DrawOn(JNIEnv *env, jclass type, jobject espView, jobject canvas) {
    espOverlay = ESP(env, espView, canvas);

    if (espOverlay.isValid()){
        DrawESP(espOverlay, espOverlay.getWidth(), espOverlay.getHeight());
    }
}



JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *globalEnv;
    vm->GetEnv((void **) &globalEnv, JNI_VERSION_1_6);

    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, HACK,NULL);
//LOGI("%s load  OK");
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL
JNI_OnUnload(JavaVM *vm, void *reserved) {}

