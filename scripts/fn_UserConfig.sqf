/*if (loadFile "\UserConfig\Bullet_Casings\UserConfigFile.hpp" != "") then
{
loadFile "\UserConfig\Bullet_Casings\UserConfigFile.hpp";
//#include "\UserConfig\Bullet_Casings\UserConfigFile.hpp"
HZ_Debug = USERSETTING_DebugMessages;
ConfigActive = USERSETTING_ConfigActive;
MaxCasingsAllowed = USERSETTING_MaxCasingsAllowed;
MaxCasingLifeTime = USERSETTING_MaxCasingLifeTime;
ApplyOnAllAI = USERSETTING_ApplyOnAllAI;
}
else
{*/
HZ_Debug = false;
ConfigActive = true;
MaxCasingsAllowed = 100;
MaxCasingLifeTime = 60*10;
ApplyOnAllAI = true;
//};
