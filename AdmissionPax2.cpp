#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// ฟังก์ชันเช็คคำสำคัญ
bool hasKeyword(string input, string keyword) {
    return input.find(keyword) != string::npos;
}

// ฟังก์ชันเช็คประวัติ
bool checkHistory(const vector<string>& history, string topic) {
    for (const string& item : history) {
        if (item == topic) return true;
    }
    return false;
}

// --- ฟังก์ชันรายละเอียดคณะ (ย่อยที่สุด) ---
void handleMajorDetails() {
    string input;
    cout << "สนใจอยากดูเกณฑ์ของหลักสูตรไหนเป็นพิเศษไหมครับ? ที่วิศวฯ มช. ของเราจะมีทั้งภาคปกติ ภาคพิเศษ แล้วก็หลักสูตรนานาชาติ (English Program) เลยนะ บอกชื่อภาคที่สนใจมาได้เลย เดี๋ยวผมเช็กให้ครับ!" << endl;
    cout << "User: ";
    getline(cin, input);

    if (hasKeyword(input, "ภาคปกติ") || hasKeyword(input, "ปกติ")) {
        cout << "AI: คณะวิศวกรรมศาสตร์ รอบนี้รับ 50 คนครับ ใช้คะแนน TGAT และ TPAT3 เกณฑ์ GPAX 3.00 ครับ" << endl;
    } else if (hasKeyword(input, "ภาคพิเศษ")) {
        cout << "AI: คณะวิศวกรรมศาสตร์ ภาคพิเศษ รับ 30 คนครับ เน้นคะแนน TGAT และ TPAT3 เกณฑ์ GPAX 3.20 ครับ" << endl;
    } else if (hasKeyword(input, "นานาชาติ") || hasKeyword(input, "English Program")) {
        cout << "AI: หลักสูตรนานาชาติ (English Program) รับ 20 คนครับ เน้นภาษาอังกฤษและคณิตศาสตร์ครับ" << endl;
    } else {
        cout << "AI: ขออภัยครับ ผมยังไม่มีข้อมูลเกณฑ์ของคณะนี้" << endl;
    }
}

// --- ฟังก์ชันจัดการเนื้อหาการรับเข้า (เจาะลึก) ---
void handleAdmissionLogic() {
    string input;
    cout << "AI: สนใจวางแผนเข้าวิศวฯ รอบไหนเป็นพิเศษไหมครับ? จะเป็นรอบ Portfolio (รอบ 1), โควตา (รอบ 2), Admission (รอบ 3) หรือรอบเก็บตก (รอบ 4) บอกผมได้เลยนะ เดี๋ยวผมช่วยเช็กรายละเอียดให้ครับ" << endl;
    cout << "User: ";
    getline(cin, input);

    if (hasKeyword(input, "1") || hasKeyword(input, "พอร์ต") || hasKeyword(input, "Portfolio")) {
        cout << "รอบ 1 หรือรอบ Portfolio จะเน้นดูที่ผลงานและความสามารถของเราเป็นหลักครับ โดยจะพิจารณาจากแฟ้มสะสมผลงาน เกรดเฉลี่ย (GPAX) และการสัมภาษณ์ครับ ความพิเศษของรอบนี้คือไม่ต้องใช้คะแนนสอบข้อเขียนอย่าง TGAT/TPAT เลยครับ" << endl;
        handleMajorDetails();
    } 
    else if (hasKeyword(input, "3") || hasKeyword(input, "แอดมิชชั่น")) {
        cout << "AI: รอบ 3 Admission เน้นคะแนนสอบส่วนกลางเป็นหลักครับ" << endl;
        handleMajorDetails();
    }
    else if (hasKeyword(input, "4") || hasKeyword(input, "เก็บตก")) {
        cout << "AI: รอบ 4 จะรับในสาขาที่ยังว่างอยู่ โดยใช้เกณฑ์คะแนนสอบเช่นกันครับ" << endl;
        handleMajorDetails();
    }
    else {
        cout << "AI: สามารถเช็ครายละเอียดเพิ่มเติมได้ที่เว็บ Admission ของมหาวิทยาลัยครับ" << endl;
    }
}

// --- ฟังก์ชันรวม (จัดการประวัติและการเรียกฟังก์ชันย่อย) ---
void handleTopic(vector<string>& history, string topicName, string firstTimeMsg, string repeatMsg) {
    if (checkHistory(history, topicName)) {
        cout << "AI: " << repeatMsg << endl;
    } else {
        cout << "AI: " << firstTimeMsg << endl;
        history.push_back(topicName); // บันทึกว่าเคยคุยเรื่องนี้แล้ว
    }

    // ถ้าเป็นเรื่องการรับเข้า ให้ไปที่ Logic เจาะลึกต่อ
    if (topicName == "การรับเข้า") {
        handleAdmissionLogic();
    } 
    // ถ้าเป็นเรื่องนักศึกษา (คุณสามารถสร้าง handleStudentLogic เพิ่มได้ในอนาคต)
    else if (topicName == "นักศึกษา") {
        string input;
        cout << "User: ";
        getline(cin, input);
        if (hasKeyword(input, "ทุน")) {
            cout << "AI: ทุนการศึกษามีทั้งทุนเรียนดีและทุนช่วยเหลือนักศึกษาครับ" << endl;
        } else {
            cout << "AI: ติดต่อสอบถามได้ที่กองพัฒนานักศึกษาครับ" << endl;
        }
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string input;
    bool keepRunning = true;
    vector<string> history;

    cout << "AI: สวัสดีครับ ยินดีต้อนรับสู่ ENGR CMU bot ครับ มีข้อมูลส่วนไหนของคณะวิศวกรรมศาสตร์ที่อยากให้ผมช่วยหาให้ไหมครับ? พิมพ์ถามได้เลย!" << endl;

    while (keepRunning) {
        cout << "\nUser: ";
        getline(cin, input);

        bool found = false;

        if (hasKeyword(input, "รับเข้า") || hasKeyword(input, "สมัคร")) {
            handleTopic(history, "การรับเข้า", 
                        "ยินดีครับ! การรับเข้ามีหลายรอบ คุณสนใจวางแผนรอบไหนเป็นพิเศษไหมครับ?", 
                        "เราเคยคุยเรื่องการรับเข้าไปแล้ว อยากเช็กข้อมูลรอบอื่นเพิ่มเติมไหม?");
            found = true;
        } 
        
        if (hasKeyword(input, "นักศึกษา") || hasKeyword(input, "ทุน")) {
            handleTopic(history, "นักศึกษา", 
                        "อยากทราบเรื่อง ทุนการศึกษา, การลงทะเบียน หรือกิจกรรมครับ?", 
                        "เรื่องนักศึกษาเราคุยกันไปแล้ว มีจุดไหนที่ยังสงสัยอยู่ไหมครับ?");
            found = true;
        }

        if (hasKeyword(input, "ลา") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "หยุด")) {
            cout << "AI: ลาก่อนครับ ขอให้โชคดีกับการเรียนนะครับ!" << endl;
            keepRunning = false;
            break;
        }

        if (!found) {
            cout << "AI: ขออภัยครับ ผมไม่เข้าใจ ลองระบุหัวข้อ 'รับเข้า' หรือ 'ทุน' ดูครับ" << endl;
        }

        if (keepRunning) {
            cout << "\nAI: ต้องการถามอะไรเพิ่มเติมอีกไหมครับ?" << endl;
        }
    }
    return 0;
}