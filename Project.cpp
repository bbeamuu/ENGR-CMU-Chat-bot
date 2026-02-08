#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void selectUserStatus(int *statusPtr); 
void handleAdmission();
void handleFreshman();
void handleGeneral();

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int select = 0; 
    string name;
    string messages;

    cout << "Chatbot : สวัสดีครับ! ยินดีต้อนรับสู่ ENGR CMU Chat Bot" << endl;
    cout << "Chatbot : ก่อนอื่น บอกชื่อของคุณให้ผมรู้จักหน่อยได้ไหมครับ?" << endl;
    cout << "User : ";
    getline(cin, name);

    cout << "Chatbot : ยินดีที่ได้รู้จักครับ คุณ " << name << "! เพื่อความแม่นยำของข้อมูล" << endl;

   while (true) {
        selectUserStatus(&select);

        if (select == 1) {
            handleAdmission();
            break;
        } else if (select == 2) {
            handleFreshman();
            break;
        } else if (select == 3) {
            handleGeneral();
            break;
        } else {
            cout << "Chatbot : เลือกเมนู 1-3 นะครับ" << endl;
        }
    }

    while (true) {
    selectUserStatus(&select);
    cin.ignore();
    if (select == 1) {
        handleAdmission();
    } else if (select == 2) {
        handleFreshman();
    } else if (select == 3) {
        handleGeneral();
    }
           
    return 0;
}

}

void selectUserStatus(int *statusPtr) {

    const char *menu[] = {
        "สนใจเข้าเรียน (Admission)",
        "นักศึกษาใหม่ปี 1 (Freshman)",
        "ถามตอบทั่วไป (General Q&A)"
    };

    int choice;
    cout << "-------------------------" << endl;
    cout << "Chatbot : กรุณาเลือกสถานะของคุณหน่อยนะครับ:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "[" << i + 1 << "] " << *(menu + i) << endl;
    }
    cout << "-------------------------" << endl;
    cout << "User (เลือกเลข): ";
    cin >> choice;

    *statusPtr = choice; 
}

void handleAdmission() {
    string userInput;
    const char *keywords[] = {"รอบรับ", "คะแนน", "เครื่องกล", "คอมพิวเตอร์", "ออก"};
    const char *responses[] = {
        "คณะเราเปิดรับ 3 รอบหลักครับ: 1.Portfolio 2.Quota 3.Admission",
        "คะแนนย้อนหลัง 3 ปี ของวิศวะ มช. คุณสามารถดูได้ที่เว็บไซต์ admission.reg.cmu.ac.th ครับ",
        "วิศวะเครื่องกล (Mechanical) จะเน้นเรื่องพลังงาน การออกแบบเครื่องจักร และยานยนต์ครับ",
        "วิศวะคอมพิวเตอร์ (Computer) จะเรียนทั้ง Hardware, Software และ Network ครับ",
        "ขอบคุณที่สนใจ Entaneer CMU นะครับ! (กำลังกลับสู่เมนูหลัก...)"
    };
    int numItems = 5;

    cout << "\nChatbot: ยินดีมากเลยครับที่คุณสนใจมาเป็นครอบครัว Entaneer CMU!" << endl;
    
    while(true) {
        cout << "\n(พิมพ์ 'ออก' เพื่อกลับเมนูหลัก) \nUser: ";
        getline(cin, userInput);

        bool found = false;
        for(int i = 0; i < numItems; i++) {
            if (userInput.find(*(keywords + i)) != string::npos) {
                cout << "Chatbot: " << *(responses + i) << endl;
                found = true;
                
                if (i == 4) return; 
                break;
            }
        }

        if (!found) {
            cout << "Chatbot: ขอโทษครับ ผมยังไม่มีข้อมูลส่วนนี้ ลองถามเรื่อง 'รอบรับ' หรือ 'คะแนน' ดูไหมครับ?" << endl;
        }
    }
}

void handleFreshman() {
   
    cout << "\nChatbot: ยินดีด้วยนะลูกช้างใหม่! การเริ่มต้นชีวิตในรั้ววิศวะอาจจะงงหน่อย แต่ผมพร้อมเป็นคู่หูให้ครับ" << endl;

    cout << "อยากรู้เรื่องอะไรถามมาได้เลย เช่น 'ตารางสอน', 'ขึ้นดอย' หรือ 'ชุดนักศึกษา เเละอื่นๆ'" << endl;

}

void handleGeneral() {
    cout << "\nChatbot: มีเรื่องอะไรที่อยากทราบเป็นพิเศษไหมครับ? พิมพ์ถามผมได้เลย!" << endl;
}
