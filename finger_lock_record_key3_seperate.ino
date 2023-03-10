#include "eeprom_anything.h"
#include "MegunoLink.h"
#include "easyButton.h"   //使用簡易按鍵的函式庫


XYPlot Fi("F"),E("E");  //Fi=finger_plot , F is used for F_Macro  E= error_plot  short for speed up

int X_key[40]; //
int Y_key[40]; //
byte n=0;
byte n_max=40;

byte Record_pin=3;
byte R=9; 
byte G=10; 
byte B=11; 
// blue = recording ,yellow=locked , red = fail to unlock ,green = unlocked and opened

int X_target; //要記錄X的值
int X_start=750; //X開始值
int X_delta=-5;  //X每次減少的值

bool clear_flag;

int X_last; //上次X值
int Y_last; //上次Y值

int X_now;  //目前X值
int Y_now;  //目前Y值

int Y_error;
int Y_error_sum;
int Y_allowed_error=1000;

void Record_key();
void next();
void plotKey();

void color( byte r ,byte g, byte b);
int my_abs(int x);

void record_error();
void check_start_end();
void lock();
void unlock();
void mismatch();























