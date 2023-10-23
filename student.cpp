#include <iostream>
#include <string>
using namespace std;


class Sort {
public:
    Sort() = delete;

    static void Bubble(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

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
class DateTime
{
    int day;
    int month;
    int year;

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
};
/// <summary>
/// Represents a student with personal information and academic performance data.
/// </summary>
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
    /// <summary>
    /// Default constructor for Student, sets default values.
    /// </summary>
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

    int* GetExamRates() const { return exam_rates; }

    int GetExamRatesCount() const
    {
        return exam_rates_count;
    }

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

    /// <summary>
    /// Print the student's personal information.
    /// </summary>
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

enum class Specialization
{
    Designer,
    Programmer,
    Mathematician,
    Linguist,
    Other
};

class Group
{
    Student* students;
    int groupSize;
    int capacity;
    string groupName;
    Specialization specialization;
    int courseNumber;

public:
    Group() : groupName("Unknown Group"), specialization(Specialization::Other), courseNumber(1), students(nullptr), groupSize(0), capacity(0) {}

    Group(const Group& other) : groupName(other.groupName), specialization(other.specialization), courseNumber(other.courseNumber), groupSize(other.groupSize), capacity(other.capacity)
    {
        students = new Student[capacity];
        for (int i = 0; i < groupSize; i++)
        {
            students[i] = other.students[i];
        }
    }

    ~Group()
    {
        delete[] students;
    }

    Student GetStudent(int index) const
    {
        if (index >= 0 && index < groupSize)
        {
            return students[index];
        }
        throw out_of_range("Invalid student index");
    }

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

    void MergeGroups(const Group& otherGroup)
    {
        for (int i = 0; i < otherGroup.groupSize; i++)
        {
            AddStudent(otherGroup.students[i]);
        }
    }

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


int main() {

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
