#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// ฟังก์ชันช่วยเช็คคำสำคัญ
bool hasKeyword(string input, string keyword) {
    return input.find(keyword) != string::npos;
}

// --- 1. ฟังก์ชันจัดการเรื่องการรับเข้า (Admission) ---
void handleAdmission() {
    string input;
    cout << "=> [การรับเข้า]: ขณะนี้เปิดรับรอบที่ 1-4 ครับ คุณสนใจเจาะจงรอบไหน หรืออยากทราบเกณฑ์คณะไหนไหม?" << endl;
    // หมายเหตุ: ตรงนี้สามารถเพิ่ม getline เพื่อถามลึกต่อเนื่องได้ตามโครงสร้างเดิม
}

// --- 2. ฟังก์ชันจัดการเรื่องข้อมูลนักศึกษา/ทุน (Student Info) ---
void handleStudentInfo() {
    cout << "=> [นักศึกษา/ทุน]: เรามีทุนการศึกษาทั้งแบบเรียนดีและขาดแคลนทุนทรัพย์ รวมถึงข้อมูลการลงทะเบียนครับ" << endl;
}

// --- 3. ฟังก์ชันจัดการคำถามอื่นๆ (General) ---
void handleOthers() {
    cout << "=> [คำถามอื่นๆ]: คุณสามารถสอบถามเรื่องแผนที่มหาลัย การติดต่อเจ้าหน้าที่ หรือระเบียบการทั่วไปได้ครับ" << endl;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    string input;
    bool keepRunning = true;

    cout << "AI: สวัสดีครับ! ผมคือระบบ AI ตอบคำถามอัตโนมัติ" << endl;
    cout << "AI: คุณสามารถถามเรื่อง การรับเข้า, นักศึกษา, ทุน หรือเรื่องอื่นๆ พร้อมกันได้เลยครับ" << endl;

    while (keepRunning) {
        cout << "\nUser: ";
        getline(cin, input);

        // 1. ตรวจสอบการบอกลาเป็นลำดับแรก
        if (hasKeyword(input, "ลา") || hasKeyword(input, "พอแล้ว") || hasKeyword(input, "หยุด") || hasKeyword(input, "ไม่")) {
            cout << "AI: รับทราบครับ ขอบคุณที่มาพูดคุยกัน ขอให้โชคดีนะครับ ลาก่อนครับ!" << endl;
            keepRunning = false;
            break;
        }

        bool foundSomething = false;

        // 2. ตรวจสอบ "การรับเข้า" (ใช้ if แยกเพื่อให้เช็คได้ทุกเงื่อนไข)
        if (hasKeyword(input, "รับเข้า") || hasKeyword(input, "สมัคร")) {
            handleAdmission();
            foundSomething = true;
        }

        // 3. ตรวจสอบ "นักศึกษา/ทุน" 
        if (hasKeyword(input, "นักศึกษา") || hasKeyword(input, "ทุน") || hasKeyword(input, "ลงทะเบียน")) {
            handleStudentInfo();
            foundSomething = true;
        }

        // 4. ตรวจสอบ "คำถามอื่นๆ"
        if (hasKeyword(input, "อื่น") || hasKeyword(input, "ถาม") || hasKeyword(input, "เรื่อง")) {
            // เช็คเพิ่มเล็กน้อยเพื่อไม่ให้มันแสดงซ้ำซ้อนถ้า User แค่พิมพ์ว่า "ถามเรื่องรับเข้า"
            if (!hasKeyword(input, "รับเข้า") && !hasKeyword(input, "นักศึกษา")) {
                handleOthers();
                foundSomething = true;
            }
        }

        // กรณีที่ User พิมพ์อะไรที่ระบบไม่เข้าใจ
        if (!foundSomething) {
            cout << "AI: ขอโทษครับ ผมไม่แน่ใจว่าคุณต้องการถามเรื่องไหน ลองระบุคำว่า 'การรับเข้า' หรือ 'นักศึกษา' ได้ไหมครับ?" << endl;
        }

        // 5. ส่วนที่ถามว่าต้องการถามอะไรอีกไหม (ถามหลังจบรอบการตอบ)
        if (keepRunning) {
            cout << "\nAI: ต้องการถามอะไรเพิ่มเติมอีกไหมครับ? (ถ้าไม่มีพิมพ์ 'ลา' ได้เลย)" << endl;
        }
    }

    return 0;
}