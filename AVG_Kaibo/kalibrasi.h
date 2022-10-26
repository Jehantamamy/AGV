#define LOWSPEED  "37 62 70 90"
#define HIGHSPEED "23 96 70 90" 
#define HOME      "89 01 80 90"

#define LINE1     "09 81 80 50"
#define LINE2     "87 26 20 90"
#define LINE3     "70 23 96 10"
#define LINE4     "47 62 70 90"
#define LINE5     "53 31 20 90"
#define LINE6     "05 16 20 90"
#define LINE7     "59 28 00 90"
#define LINE8     "04 99 70 90"
#define LINE9     "47 08 67 70"
#define LINE10    "24 02 20 90"
#define LINE11    "85 81 70 90"
#define LINE12    "47 29 71 90"
#define LINE13    "45 77 80 90"
#define LINE14    "`z 30 90"
#define LINE15    "60 83 57 70"
#define LINE16    "69 04 90 90"
#define LINE17    "56 68 49 80"
#define LINE18    "50 74 30 90"
#define LINE19    "67 60 70 90"
#define LINE20    "72 51 30 90"
#define LINE21    "74 80 80 90"
#define LINE22    "35 62 68 80"
#define LINE23    "85 07 98 80"
#define LINE24    "99 87 70 90"
#define LINE25    "88 00 80 90"
#define LINE26    "81 12 10 90" //rusak
#define LINE27    "97 39 70 90"
#define LINE28    "43 88 20 90"
#define LINE29    "73 27 20 90"
#define LINE30    "81 19 20 90"
#define LINE31    "06 12 81 90"
#define LINE32    "88 75 49 80"
#define LINE33    "67 60 70 90"
#define LINE34    "67 60 70 90"
#define LINE35    "82 71 20 90"
#define LINE36    "84 40 78 80"
#define LINE37    "05 05 80 90"
#define LINE38    "89 88 90 90"
#define LINE39    "85 52 30 90"
#define LINE40    "78 84 90 90"
#define LINE41    "93 56 80 90"
#define LINE42    "26 50 20 90"
#define LINE43    "43 25 20 90"
#define LINE44    "77 38 78 80"
#define LINE45    " "
#define LINE46    "89BA62"
#define LINE47    "89BA62"
#define LINE48    "89BA62"
#define LINE49    "89BA62"
#define LINE50    "89BA62"

//#define KECEPATANLOWSPEED 50
//#define KECEPATANHIGHSPEED 85
int KecepatanMotor=0, KecepatanMinimal=0, KecepatanMaksimal=100;

#define PUTIH 0
#define HITAM 1 

byte kondisi1=0,kondisi2=0;
const int KAL[8] = {200, 200, 200, 200, 200, 200, 200, 200}; //0,1,2,3 dst//kiri ke kanan

int Kp= 17, Kd=25; //PID Setting
int DelayKeluar=25;
unsigned int DelayMusic=50000;
byte GARIS=HITAM;
String LINESTOP;
