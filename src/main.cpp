#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

// Umur dalam tahun
int yearsOld(tm* inputTgl, tm* currentTgl);
// Umur dalam bulan
int monthsOld(tm* inputTgl, tm* currentTgl);
// Hari dalam seminggu (Minggu, Senin, ..., Sabtu)
string dayOfDate(tm* inputTgl);

int main(int argc, char ** argv) 
{
    // time_t -> data structure untuk waktu
    time_t currentTime;

    // set variable currentTime ke data sekarang
    time(&currentTime);

    // ubah ke localtime (UTC+7)
    tm* currentTgl = localtime(&currentTime);

    // print tanggal sekarang (di comment)
    // cout    <<" year:" << timePtr->tm_year+1900 <-- perlu diperhatikan
    //        <<" month:"<< timePtr->tm_mon+1
    //        <<" day:" << timePtr->tm_mday <<endl;

    //int yearnow = currentTgl->tm_year+1900;    
    //int monthnow = currentTgl->tm_mon+1;
    //int daynow = currentTgl->tm_mday;
    //int dayofweek = currentTgl->tm_wday;       // <-- start dari hari minggu

    // input tanggal lahir
    int yearinput, monthinput, dayinput;
    string inputstr;
    char ch;
    // silahkan uncomment kode dibawah untuk debugging
    cout << "Input tanggal dalam format DD/MM/YYYY:";
    cin >> inputstr;
    stringstream ss(inputstr);
    ss >> dayinput >> ch >> monthinput >> ch >> yearinput;

    // silahkan uncomment untuk debugging
    //cout << "Tanggal Input: " << dayinput << "/" << monthinput << "/" << yearinput << endl;
    
    // buat tm* untuk tanggal input
    tm* inputTgl = new tm();
    inputTgl->tm_year = yearinput-1900;
    inputTgl->tm_mon = monthinput-1;
    inputTgl->tm_mday = dayinput;

    // ----------------------------------------------------------------------------------------------------------------
    // --- Ubah di sini
    // ---  * output yang diinginkan: 32 390 Selasa
    // ---                  32 -> usia dalam tahun, 390 -> usia dalam bulan, Selasa -> hari dari tanggal input
    // ----------------------------------------------------------------------------------------------------------------
    int ageOfYear = yearsOld(inputTgl, currentTgl);
    int ageOfMonth = monthsOld(inputTgl, currentTgl);
    string dayName = dayOfDate(inputTgl);

    cout << ageOfYear << " " << ageOfMonth << " " << dayName;
    // ----------------------------------------------------------------------------------------------------------------

    return 0;
}

//*********************************************************************************************************************
// Silahkan masukkan kode Anda pada fungsi-fungsi berikut
//*********************************************************************************************************************
int yearsOld(tm* inputTgl, tm* currentTgl)
{
    int age = currentTgl->tm_year - inputTgl->tm_year;
    if (currentTgl->tm_mon < inputTgl->tm_mon ||
        (currentTgl->tm_mon == inputTgl->tm_mon && currentTgl->tm_mday < inputTgl->tm_mday))
    {
        age--;
    }
    return age;
}
//*********************************************************************************************************************
//*********************************************************************************************************************
int monthsOld(tm* inputTgl, tm* currentTgl)
{
    int age = (currentTgl->tm_year - inputTgl->tm_year) * 12 + (currentTgl->tm_mon - inputTgl->tm_mon);
    if (currentTgl->tm_mday < inputTgl->tm_mday)
    {
        age--;
    }
    return age;
}
//*********************************************************************************************************************
//*********************************************************************************************************************
string dayOfDate(tm* inputTgl)
{
    string dayNames[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    mktime(inputTgl); 
    return dayNames[inputTgl->tm_wday];
}
//*********************************************************************************************************************
//*********************************************************************************************************************

