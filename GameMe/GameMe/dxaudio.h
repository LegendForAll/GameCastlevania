#include "dsutil.h"


int InitDirectSound(HWND);
//CSound* LoadSound(char*);
CSound* LoadSound(string filename);
void PlaySound(CSound*);
void LoopSound(CSound*);
void StopSound(CSound*);