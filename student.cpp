#include <iostream>
#include <string>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

class DateTime {
    int day;
    int month;
    int year;
    static time_t t;
    static struct tm* now;

public:
    /// <summary>
    /// // Default constructor initializes the date to January 1, 2000.
    /// </summary>
    DateTime() : day(1), month(1), year(2000) {}

    DateTime(int day, int month, int year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }
    /// <summary>
    /// Set the day of the date.
    /// </summary>
    /// <param name="day"></param>
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
    /// <summary>
    /// Get the day of the date.
    /// </summary>
    /// <returns></returns>
    int GetDay() const
    {
        return day;
    }
    /// <summary>
    /// Set the month of the date.
    /// </summary>
    /// <param name="month"></param>
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
    /// <summary>
    /// Get the month of the date.
    /// </summary>
    /// <returns></returns>
    int GetMonth() const
    {
        return month;
    }
    /// <summary>
    /// Set the year of the date.
    /// </summary>
    /// <param name="year"></param>
    void SetYear(int year)
    {
        this->year = year;
    }
    /// <summary>
    /// // Get the year of the date.
    /// </summary>
    /// <returns></returns>
    int GetYear() const
    {
        return year;
    }
    /// <summary>
    /// Print the date in the format "day.month.year."
    /// </summary>
    void Print() const
    {
        cout << day << "." << month << "." << year;
    }

    int PrintHours()
    {
        return now->tm_hour;
    }

    int PrintMinutes()
    {
        return now->tm_min;
    }

    int PrintSeconds()
    {
        return now->tm_sec;
    }
};

istream& operator>>(istream& is, DateTime& dt)
{
    int day, month, year;
    cout << "Year:" << endl;
    is >> year;
    dt.SetYear(year);
    cout << "Month:" << endl;
    is >> month;
    dt.SetMonth(month);
    cout << "Day:" << endl;
    is >> day;
    dt.SetDay(day);
    return is;
}

ostream& operator<<(ostream& os, const DateTime& dt)
{
    dt.Print(); 
    return os;
}


/// <summary>
/// 
/// </summary>
class Logger {
    static Logger* instance;
    int log_count = 0;
    string path = "C:/Users/ihora/source/repos/student/log.txt";
    DateTime* date_time;

    Logger()
    {
    }

public:
    static Logger* GetInstance()
    {
        return instance == nullptr ? instance = new Logger() : instance;
    }

    void Write(string message)
    {
        log_count++;
        int hours = date_time->PrintHours(), minutes = date_time->PrintMinutes(), seconds = date_time->PrintSeconds();
        string time = to_string(hours);
        time += ':';
        time += to_string(minutes);
        time += ':';
        time += to_string(seconds);

        ofstream output_file(path, ios::app);
        if (output_file.is_open())
        {
            output_file << message << " at " << time << "\n";
            cout << message << " at " << time << '\n';
            output_file.close();
        }
        else
        {
        }
    }

    void Write(int value)
    {
        Write(to_string(value));
    }
};


/// <summary>
/// 
/// </summary>
class Sort {
public:
    Sort() = delete;

    /// <summary>
    /// 
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="size"></param>
    static void Bubble(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    /// <summary>
    /// 
    /// </summary>
    static void Selection(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
};

/// <summary>
/// Represents a date and time with day, month, and year.
/// </summary>


/// <summary>
/// Represents a student with personal information and academic performance data.
/// </summary>
class Student {
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
    /// <summary>
    /// Default constructor for Student, sets default values.
    /// </summary>
    Student() : Student("John", "Doe", "Smith", "123 Main St.", "0977537789", { 1, 1, 2000 }, { 1, 1, 2022 }) {
        ThrowError();
        Logger::GetInstance()->Write("An object of type Student was created.");
    }

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    Student(string name, string surname) : Student(name, surname, "Smith", "123 Main St.", "0977537789", { 1, 1, 2000 }, { 1, 1, 2022 }) {
        ThrowError();
        Logger::GetInstance()->Write("An object of type Student was created.");
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="birthday"></param>
    Student(string name, string surname, string father_name, string address, string phone_number, const DateTime& birthday, const DateTime& study_start)
    {
        Logger::GetInstance()->Write("An object of type Student was created.");
        ThrowError();
        SetName(name);
        SetSurname(surname);
        SetFatherName(father_name);
        SetAddress(address);
        SetPhoneNumber(phone_number);
        SetBirthday(birthday);
        SetStudyStart(study_start);
    }

    /// <summary>
    /// 
    /// </summary>
    ~Student()
    {
        Logger::GetInstance()->Write("An object of type Student was destroyed.");

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

    static int student_count;

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    bool CountError()
    {
        return student_count <= 15;
    }

    /// <summary>
    /// 
    /// </summary>
    void ThrowError()
    {
        try {
            if (CountError())
                student_count++;
            else
                throw 1;
        }
        catch (int)
        {
            cout << "Maximum Student object limit reached." << endl;
        }
    }
    /// <summary>
    /// Set the student's name. Get the student's name.
    /// </summary>
    void SetName(string name) { this->name = name; }
    string GetName() const { return name; }

    /// <summary>
    /// Set the student's surname. Get the student's surname.
    /// </summary>
    void SetSurname(string surname) { this->surname = surname; }
    string GetSurname() const { return surname; }

    /// <summary>
    /// Set the student's father's name. Get the student's father's name.
    /// </summary>
    void SetFatherName(string father_name) { this->father_name = father_name; }
    string GetFatherName() const { return father_name; }

    /// <summary>
    /// Set the student's address. Get the student's address.
    /// </summary>
    void SetAddress(string address) { this->address = address; }
    string GetAddress() const { return address; }

    /// <summary>
    /// Set the student's phone number
    /// </summary>
    /// <param name="phone_number"></param>
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

    /// <summary>
    /// Get the student's phone number.
    /// </summary>
    /// <returns></returns>
    string GetPhoneNumber() const { return phone_number; }

    /// <summary>
    /// Set the student's birthday.
    /// </summary>
    /// <param name="birthday"></param>
    void SetBirthday(const DateTime& birthday)
    {
        this->birthday = birthday;
    }

    /// <summary>
    /// Get the student's birthday.
    /// </summary>
    /// <returns></returns>
    DateTime GetBirthday() const { return birthday; }

    /// <summary>
    /// Set the student's study start date.
    /// </summary>
    /// <param name="study_start"></param>
    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }

    /// <summary>
    /// Get the student's study start date.
    /// </summary>
    /// <returns></returns>
    DateTime GetStudyStart() const { return study_start; }

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    int* GetExamRates() const { return exam_rates; }

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    int GetExamRatesCount() const
    {
        return exam_rates_count;
    }

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    double CalculateAverageHomeworkRate() const
    {
        if (hometask_rates_count == 0 || hometask_rates == nullptr)
        {
            return 0.0; // Return 0 if there are no homework rates or the array is not allocated.
        }

        double totalRate = 0.0;
        for (int i = 0; i < hometask_rates_count; i++)
        {
            totalRate += hometask_rates[i];
        }

        return totalRate / static_cast<double>(hometask_rates_count);
    }

    /// <summary>
    /// Add a homework rate to the student's record.
    /// </summary>
    /// <param name="rate"></param>
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

    /// <summary>
    /// Add a practice rate to the student's record.
    /// </summary>
    /// <param name="rate"></param>
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

    /// <summary>
    /// Add an exam rate to the student's record.
    /// </summary>
    /// <param name="rate"></param>
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

    /// <summary>
    /// Print the student's homework rates.
    /// </summary>
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

    /// <summary>
    /// Print the student's practice rates.
    /// </summary>
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

    /// <summary>
    /// Print the student's exam rates.
    /// </summary>
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

    Student(const string& n) : name(n) {}

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

bool operator==(const Student& left, const Student& right)
{
    return left.CalculateAverageHomeworkRate() == right.CalculateAverageHomeworkRate();
}

bool operator!=(const Student& left, const Student& right)
{
    return left.CalculateAverageHomeworkRate() != right.CalculateAverageHomeworkRate();
}

bool operator>(const Student& left, const Student& right)
{
    return left.CalculateAverageHomeworkRate() > right.CalculateAverageHomeworkRate();
}

bool operator<(const Student& left, const Student& right)
{
    return left.CalculateAverageHomeworkRate() < right.CalculateAverageHomeworkRate();
}

enum class Specialization {
    Designer,
    Programmer,
    Mathematician,
    Linguist,
    Other,
    Unknown
};

/// <summary>
/// 
/// </summary>
class Group {
    Student* students;
    int groupSize;
    int capacity;
    string groupName;
    Specialization specialization;
    int courseNumber;

public:

    friend istream& operator>>(istream& is, Group& obj);
    friend ostream& operator<<(ostream& os, Group& obj);

    /// <summary>
    /// 
    /// </summary>
    Group() : groupName("Unknown Group"), specialization(Specialization::Other), courseNumber(1), students(nullptr), groupSize(0), capacity(0) {
        ThrowError();
        Logger::GetInstance()->Write("An object of type Group was created.");
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="other"></param>
    Group(const Group& other) : groupName(other.groupName), specialization(other.specialization), courseNumber(other.courseNumber), groupSize(other.groupSize), capacity(other.capacity)
    {
        Logger::GetInstance()->Write("An object of type Group was created.");
        ThrowError();
        students = new Student[capacity];
        for (int i = 0; i < groupSize; i++)
        {
            students[i] = other.students[i];
        }
    }

    /// <summary>
    /// 
    /// </summary>
    ~Group()
    {
        Logger::GetInstance()->Write("An object of type Group was destroyed.");
        delete[] students;
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    Student GetStudent(int index) const
    {
        if (index >= 0 && index < groupSize)
        {
            return students[index];
        }
        throw out_of_range("Invalid student index");
    }

    static int group_count;

    /// <summary>
    /// 
    /// </summary>
    bool CountError()
    {
        return group_count <= 15;
    }

    /// <summary>
    /// 
    /// </summary>
    void ThrowError()
    {
        try {
            if (CountError())
                group_count++;
            else
                throw 1;
        }
        catch (int)
        {
            cout << "Maximum Group object limit reached." << endl;
        }
    }

    /// <summary>
    /// 
    /// </summary>
    void ShowAllStudents() const
    {
        cout << "Group Name: " << groupName << endl;
        cout << "Specialization: " << GetSpecializationString() << endl;
        cout << "Course Number: " << courseNumber << endl;

        cout << "Students in alphabetical order:" << endl;
        for (int i = 0; i < groupSize; i++)
        {
            cout << students[i].GetSurname() << " " << students[i].GetName() << endl;
        }
    }

    int getGroupSize() const
    {
        return groupSize;
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="newStudent"></param>
    void AddStudent(const Student& newStudent)
    {
        if (groupSize == capacity)
        {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            Student* newStudents = new Student[newCapacity];

            for (int i = 0; i < groupSize; i++)
            {
                newStudents[i] = students[i];
            }

            delete[] students;
            students = newStudents;
            capacity = newCapacity;
        }

        students[groupSize] = newStudent;
        groupSize++;
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="otherGroup"></param>
    void MergeGroups(const Group& otherGroup)
    {
        for (int i = 0; i < otherGroup.groupSize; i++)
        {
            AddStudent(otherGroup.students[i]);
        }
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="targetGroup"></param>
    /// <param name="studentIndex"></param>
    void TransferStudent(Group& targetGroup, int studentIndex)
    {
        if (studentIndex >= 0 && studentIndex < groupSize)
        {
            Student studentToTransfer = students[studentIndex];

            for (int i = studentIndex; i < groupSize - 1; i++)
            {
                students[i] = students[i + 1];
            }

            groupSize--;

            targetGroup.AddStudent(studentToTransfer);
        }
        else
        {
            throw out_of_range("Invalid student index for transfer");
        }
    }

    /// <summary>
    /// 
    /// </summary>
    void RemoveFailedStudents()
    {
        int passCount = 0;

        for (int i = 0; i < groupSize; i++)
        {
            bool passed = true;

            int examRatesCount = students[i].GetExamRatesCount();

            int* examRates = students[i].GetExamRates();

            for (int j = 0; j < examRatesCount; j++)
            {
                if (examRates[j] < 4)
                {
                    passed = false;
                    break;
                }
            }

            if (passed)
            {
                students[passCount] = students[i];
                passCount++;
            }
        }

        groupSize = passCount;
    }

    /// <summary>
    /// 
    /// </summary>
    void RemoveWorstStudent()
    {
        if (groupSize == 0)
        {
            return;
        }

        int worstStudentIndex = 0;
        double worstAverageRate = students[0].CalculateAverageHomeworkRate();

        for (int i = 1; i < groupSize; i++)
        {
            double averageRate = students[i].CalculateAverageHomeworkRate();
            if (averageRate < worstAverageRate)
            {
                worstStudentIndex = i;
                worstAverageRate = averageRate;
            }
        }

        for (int i = worstStudentIndex; i < groupSize - 1; i++)
        {
            students[i] = students[i + 1];
        }

        groupSize--;
    }

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GetSpecializationString() const
    {
        switch (specialization)
        {
        case Specialization::Designer: return "Designer";
        case Specialization::Programmer: return "Programmer";
        case Specialization::Mathematician: return "Mathematician";
        case Specialization::Linguist: return "Linguist";
        case Specialization::Other: return "Other";
        default: return "Unknown";
        }
    }
};

bool operator == (const Group& left, const Group& right)
{
    return left.getGroupSize() == right.getGroupSize();
}

bool operator != (const Group& left, const Group& right)
{
    return left.getGroupSize() != right.getGroupSize();
}

ostream& operator<<(ostream& cout, const Specialization& specialization)
{
    switch (specialization)
    {
    case Specialization::Designer: cout << "Designer"; break;
    case Specialization::Programmer: cout << "Programmer"; break;
    case Specialization::Mathematician: cout << "Mathematician"; break;
    case Specialization::Linguist: cout << "Linguist"; break;
    case Specialization::Other: cout << "Other"; break;
    default: cout << "Unknown";
    }
    return cout;
}

istream& operator>>(istream& cin, Specialization& specialization)
{
    int specializationInt;
    cin >> specializationInt;

    switch (specializationInt)
    {
    case 0: specialization = Specialization::Designer; break;
    case 1: specialization = Specialization::Programmer; break;
    case 2: specialization = Specialization::Mathematician; break;
    case 3: specialization = Specialization::Linguist; break;
    case 4: specialization = Specialization::Other; break;
    default: specialization = Specialization::Unknown;
    }

    return cin;
}

istream& operator>>(istream& cin, Group& obj)
{
    cout << "Type a group size:" << endl;
    cin >> obj.groupSize;
    cout << "Type a group course:" << endl;
    cin >> obj.courseNumber;
    cout << "Type a group-name:" << endl;
    cin >> obj.groupName;
    cout << "Type a group specialty:" << endl;
    cin >> obj.specialization;

    obj.students = new Student[obj.groupSize];

    return cin;
}

ostream& operator<<(ostream& cout, Group& obj)
{
    cout << "Group name: " << obj.groupName << endl;
    cout << "Specialty: " << obj.specialization << endl;

    for (int i = 0; i < obj.groupSize; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Name: " << obj.students[i].GetName() << endl;
        cout << "Surname: " << obj.students[i].GetSurname() << endl;
        cout << "Birthday: ";
        obj.students[i].GetBirthday().Print();
        cout << "Study start date: ";
        obj.students[i].GetStudyStart().Print();
    }

    return cout;
}


class Fraction {
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int numerator, int denominator);


    Fraction(int value)
    {
        numerator = value;
        denominator = 1;
    }

    double GetDecimal() const;
    void Print() const;
    void PrintDecimal() const;

    static Fraction Sum(const Fraction& left, const Fraction& right);
    bool GreaterThan(const Fraction& another) const;
    bool IsEquals(const Fraction& another) const;
    bool LessThan(const Fraction& another) const;

    int GetNumerator() const;
    int GetDenominator() const;
    void SetNumerator(int numerator);
    void SetDenominator(int denominator);
};

Fraction operator + (const Fraction& f1, const Fraction& f2);
void F1(Fraction a);
Fraction F2();

Fraction::Fraction() : Fraction(0, 1)
{

}

Fraction::Fraction(int numerator, int denominator)
{
    SetNumerator(numerator);
    SetDenominator(denominator);
}

double Fraction::GetDecimal() const
{
    return (double)numerator / denominator;
}

void Fraction::Print() const
{
    cout << numerator << "/" << denominator << "\n";
}

void Fraction::PrintDecimal() const
{
    cout << GetDecimal() << "\n";
}

int Fraction::GetNumerator() const
{
    return numerator;
}

int Fraction::GetDenominator() const
{
    return denominator;
}

void Fraction::SetNumerator(int numerator)
{
    this->numerator = numerator;
}

void Fraction::SetDenominator(int denominator)
{
    if (denominator != 0)
    {
        this->denominator = denominator;
    }
    else
    {
        throw "ERROR!";
    }
}

bool Fraction::LessThan(const Fraction& right) const
{
    return this->GetDecimal() < right.GetDecimal();
}

bool Fraction::GreaterThan(const Fraction& right) const
{
    return this->GetDecimal() > right.GetDecimal();
}

bool Fraction::IsEquals(const Fraction& right) const
{
    return this->GetDecimal() == right.GetDecimal();
}

void F1(Fraction a)
{
    cout << "explicit c-tor test global function F1\n";
}

Fraction F2()
{
    cout << "explicit c-tor test global function F2\n";
    return 5;
}

Fraction Fraction::Sum(const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.SetNumerator(left.numerator * right.denominator + right.numerator * left.denominator);
    result.SetDenominator(left.denominator * right.denominator);
    return result;
}

Fraction operator + (const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.SetNumerator(left.GetNumerator() * right.GetDenominator() + right.GetNumerator() * left.GetDenominator());
    result.SetDenominator(left.GetDenominator() * right.GetDenominator());
    return result;
}

Fraction operator + (const Fraction& left, int right)
{
    Fraction result;
    result.SetNumerator(left.GetNumerator() + (right * left.GetDenominator()));
    result.SetDenominator(left.GetDenominator());
    return result;
}

Fraction operator + (int left, const Fraction& right)
{
    Fraction result;
    result.SetNumerator((left * right.GetDenominator()) + right.GetDenominator());
    result.SetDenominator(right.GetDenominator());
    return result;
}

Fraction operator + (const Fraction& left, double right)
{
    Fraction result, tmp;
    tmp.SetNumerator((int)right);
    if (right - (int)right > 0)
        tmp.SetDenominator((right - (int)right) * 10);
    else
        tmp.SetDenominator(1);
    result.SetNumerator(left.GetNumerator() * tmp.GetDenominator() + tmp.GetNumerator() * left.GetDenominator());
    result.SetDenominator(left.GetDenominator() * tmp.GetDenominator());
    return result;
}

Fraction operator + (double left, const Fraction& right)
{
    Fraction result, tmp;
    tmp.SetNumerator((int)left);
    if (left - (int)left > 0)
        tmp.SetDenominator((left - (int)left) * 10);
    else
        tmp.SetDenominator(1);
    result.SetNumerator(right.GetNumerator() * tmp.GetDenominator() + tmp.GetNumerator() * right.GetDenominator());
    result.SetDenominator(right.GetDenominator() * tmp.GetDenominator());
    return result;
}

Fraction operator - (const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.SetNumerator(left.GetNumerator() * right.GetDenominator() - right.GetNumerator() * left.GetDenominator());
    result.SetDenominator(left.GetDenominator() * right.GetDenominator());
    return result;
}

Fraction operator * (const Fraction& left, const Fraction& right)
{
    Fraction result;
    result.SetNumerator(left.GetNumerator() * right.GetNumerator());
    result.SetDenominator(left.GetDenominator() * right.GetDenominator());
    return result;
}

Fraction operator / (const Fraction& left, const Fraction& right)
{
    if (right.GetNumerator() == 0) {
        throw "ERROR: Division by zero.";
    }

    Fraction result;
    result.SetNumerator(left.GetNumerator() * right.GetDenominator());
    result.SetDenominator(left.GetDenominator() * right.GetNumerator());
    return result;
}

int Student::student_count = 0;
int Group::group_count = 0;

time_t DateTime::t = time(0);
tm* DateTime::now = localtime(&t);
Logger* Logger::instance = nullptr;

int main() {

    string name = "Ihor";
    Student s = name;
    s.Print();

    Fraction a(2, 5); // 1/2
    double b = 6;
    Fraction result = a + b;
    cout << result.GetNumerator() << '/' << result.GetDenominator();

    Logger::GetInstance()->Write("Main started by Alex");

    int ar[] = { 1, 6, 2, 7, 3, 8, 4, 9, 5, 10 };
    int n = sizeof(ar) / sizeof(ar[0]);

    Sort::Bubble(ar, n);

    for (int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;

    int ar2[] = { 1, 6, 2, 7, 3, 8, 4, 9, 5, 10 };
    Sort::Selection(ar2, n);

    for (int i = 0; i < n; i++) {
        cout << ar2[i] << " ";
    }
    cout << endl;

    Logger::GetInstance();
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

    Logger::GetInstance()->Write("Main ended by Alex");

    return 0;
}
