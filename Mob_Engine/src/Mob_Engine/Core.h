#ifdef MOB_DLL_EXPORT
	#define MOB_API __declspec(dllexport)
#else
	#define MOB_API __declspec(dllimport)
#endif