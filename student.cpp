#include <iostream>
#include <string>
using namespace std;

class DateTime
{
    int day;
    int month;
    int year;

public:
    DateTime() : day(1), month(1), year(2000) {}

    DateTime(int day, int month, int year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }

    void SetDay(int day)
    {
        if (day > 0 && day <= 31)
        {
            this->day = day;
        }
        else
        {
            cout << "Invalid day value!" << endl;
            throw "ERROR!";
        }
    }

    int GetDay() const
    {
        return day;
    }

    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            cout << "Invalid month value!" << endl;
            throw "ERROR!";
        }
    }

    int GetMonth() const
    {
        return month;
    }

    void SetYear(int year)
    {
        this->year = year;
    }

    int GetYear() const
    {
        return year;
    }

    void Print() const
    {
        cout << day << "." << month << "." << year;
    }
};

class Student
{
    string name;
    string surname;
    string father_name;
    string address;
    string phone_number;
    DateTime birthday;
    DateTime study_start;

    int* hometask_rates;
    int hometask_rates_count;

    int* practice_rates;
    int practice_rates_count;

    int* exam_rates;
    int exam_rates_count;

public:
    Student() : Student("John", "Doe", "Smith", "123 Main St.", "0977537789", { 1, 1, 2000 }, { 1, 1, 2022 }) {}

    Student(string name, string surname) : Student(name, surname, "Smith", "123 Main St.", "0977537789", { 1, 1, 2000 }, { 1, 1, 2022 }) {}

    Student(string name, string surname, string father_name, string address, string phone_number, const DateTime& birthday, const DateTime& study_start)
    {
        SetName(name);
        SetSurname(surname);
        SetFatherName(father_name);
        SetAddress(address);
        SetPhoneNumber(phone_number);
        SetBirthday(birthday);
        SetStudyStart(study_start);
    }

    ~Student()
    {
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
        if (practice_rates != nullptr)
        {
            delete[] practice_rates;
            practice_rates = nullptr;
        }
        if (exam_rates != nullptr)
        {
            delete[] exam_rates;
            exam_rates = nullptr;
        }
    }

    void SetName(string name) { this->name = name; }
    string GetName() const { return name; }

    void SetSurname(string surname) { this->surname = surname; }
    string GetSurname() const { return surname; }

    void SetFatherName(string father_name) { this->father_name = father_name; }
    string GetFatherName() const { return father_name; }

    void SetAddress(string address) { this->address = address; }
    string GetAddress() const { return address; }

    void SetPhoneNumber(string phone_number)
    {
        if (phone_number.length() == 10)
            this->phone_number = phone_number;
        else
        {
            cout << "Invalid phone number!" << endl;
            throw "ERROR!";
        }
    }

    string GetPhoneNumber() const { return phone_number; }

    void SetBirthday(const DateTime& birthday)
    {
        this->birthday = birthday;
    }

    DateTime GetBirthday() const { return birthday; }

    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }

    DateTime GetStudyStart() const { return study_start; }

    void AddHometaskRate(int rate)
    {
        if (rate >= 1 && rate <= 12)
        {
            if (hometask_rates == nullptr)
                hometask_rates = new int[1];
            else
            {
                int* temp = new int[hometask_rates_count + 1];
                for (int i = 0; i < hometask_rates_count; i++)
                    temp[i] = hometask_rates[i];
                delete[] hometask_rates;
                hometask_rates = temp;
            }
            hometask_rates[hometask_rates_count] = rate;
            hometask_rates_count++;
        }
        else
        {
            cout << "Invalid value for home task rate!" << endl;
            throw "ERROR!";
        }
    }

    void AddPracticeRate(int rate)
    {
        if (rate >= 1 && rate <= 12)
        {
            if (practice_rates == nullptr)
                practice_rates = new int[1];
            else
            {
                int* temp = new int[practice_rates_count + 1];
                for (int i = 0; i < practice_rates_count; i++)
                    temp[i] = practice_rates[i];
                delete[] practice_rates;
                practice_rates = temp;
            }
            practice_rates[practice_rates_count] = rate;
            practice_rates_count++;
        }
        else
        {
            cout << "Invalid value for practice rate!" << endl;
            throw "ERROR!";
        }
    }

    void AddExamRate(int rate)
    {
        if (rate >= 1 && rate <= 12)
        {
            if (exam_rates == nullptr)
                exam_rates = new int[1];
            else
            {
                int* temp = new int[exam_rates_count + 1];
                for (int i = 0; i < exam_rates_count; i++)
                    temp[i] = exam_rates[i];
                delete[] exam_rates;
                exam_rates = temp;
            }
            exam_rates[exam_rates_count] = rate;
            exam_rates_count++;
        }
        else
        {
            cout << "Invalid value for exam rate!" << endl;
            throw "ERROR!";
        }
    }

    void PrintHometaskRates() const
    {
        cout << "Home Task Rates: ";
        for (int i = 0; i < hometask_rates_count; i++)
        {
            cout << hometask_rates[i];
            if (i < hometask_rates_count - 1)
                cout << ", ";
        }
        cout << endl;
    }

    void PrintPracticeRates() const
    {
        cout << "Practice Rates: ";
        for (int i = 0; i < practice_rates_count; i++)
        {
            cout << practice_rates[i];
            if (i < practice_rates_count - 1)
                cout << ", ";
        }
        cout << endl;
    }

    void PrintExamRates() const
    {
        cout << "Exam Rates: ";
        for (int i = 0; i < exam_rates_count; i++)
        {
            cout << exam_rates[i];
            if (i < exam_rates_count - 1)
                cout << ", ";
        }
        cout << endl;
    }

    void Print() const
    {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Father Name: " << father_name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Birthday: ";
        birthday.Print();
        cout << endl;
        cout << "Study Start Date: ";
        study_start.Print();
        cout << endl;
    }
};

int main()
{
    Student s1;
    s1.Print();

    cout << "Adding home task rates:" << endl;
    s1.AddHometaskRate(10);
    s1.AddHometaskRate(11);
    s1.PrintHometaskRates();
    cout << endl;

    cout << "Adding practice rates:" << endl;
    s1.AddPracticeRate(8);
    s1.AddPracticeRate(9);
    s1.PrintPracticeRates();
    cout << endl;

    cout << "Adding exam rates:" << endl;
    s1.AddExamRate(11);
    s1.AddExamRate(12);
    s1.PrintExamRates();

    return 0;
}
