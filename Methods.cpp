#pragma once
#include "Methods.h"
#include <iostream>

using namespace std;

// конструктор
Set() {
    Head = NULL;
    Tail = NULL;
};

// конструктор копирования
Set(const Set &set) {
    // Выполняем копирование значений
    Head = set.Head;
    Tail = set.Tail;

}

// перегрузка присваивания Set и Set
Set& operator= (const Set set)
{
    // Выполняем копирование значений
    Head = set.Head;
    Tail = set.Tail;

    // Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
    return *this;
}

// перегрузка присваивания Set и int
Set& operator= (int d)
{
    this + d;

    return *this;
}


// пересечение множеств
Set operator* (Set s) {
    element *multitude_1;
    element *point_1;
    element *multitude_2;
    element *point_2;
    Set result;
    // если одно из множеств пусто
    if (this->Head == NULL || s.Head == NULL)
        return result;
    else { // если в обоих множествах по одному эл-ту
        if (Head->next == Head && s.Head->next == s.Head) {
            if (s.Head->number == this->Head->number)
                result + Head->number;
            return result;

        } else { // поиск эл-та из одного мн-ва в другом
            if (length() < s.length()) {
                multitude_1 = Head;
                multitude_2 = s.Head;
                point_2 = multitude_2->next;
                while (multitude_1 != Tail) {
                    while (point_2 != s.Head && multitude_1->number != multitude_2->number) {
                        multitude_2 = multitude_2->next;
                        point_2 = point_2->next;
                    }
                    if (multitude_1->number == multitude_2->number)
                        result + multitude_2->number;
                    multitude_1 = multitude_1->next;
                    multitude_2 = s.Head;
                    point_2 = multitude_2->next;
                }
                if (multitude_1 == Tail) {
                    while (multitude_1->number != multitude_2->number && point_2 != s.Head) {
                        multitude_2 = multitude_2->next;
                        point_2 = point_2->next;
                    }
                    if (multitude_1->number == multitude_2->number)
                        result + multitude_2->number;
                }
            } else {
                multitude_1 = Head;
                point_1 = multitude_1->next;
                multitude_2 = s.Head;
                while (multitude_2 != NULL) {
                    while (multitude_1->number != multitude_2->number && point_1 != NULL) {
                        multitude_1 = multitude_1->next;
                        point_1 = point_1->next;
                    }
                    if (multitude_1->number == multitude_2->number)
                        result + multitude_2->number;
                    multitude_1 = Head;
                    point_1 = multitude_1->next;
                    multitude_2 = multitude_2->next;
                }
            }
            return result;
        }
    }
}

// пересечение множества с элементом
Set operator* (int a) { // исходное множество при этом не меняется
    element *multiplate;
    element *point;
    Set s;
    // если у нас пустое множество
    if (this->Head == NULL) {
        return s;
    } else {
        multiplate = Head;
        point = Head->next;
        if (multiplate == point) { //если один элемент, то ничего удалять из текущего множества не нужно
            if (multiplate->number == a)
                return s + a;
        } else {
            while (point != NULL && (point->number != a)) {
                multiplate = point;
                point = multiplate->next;
            }
        } if (point->number == a) {
            return s + a;
        } else if (point == Head) { // если дошли до конца множества
            return s;
        }
    }
}

// пересечение эл-та и мн-ва
friend Set operator* (int a, Set& s) {
    return s * a;
}

// поиск эл-та
bool search (int a) {
    element *multiplate;
    element *point;
    // если у нас пустое множество
    if (this->Head == NULL) {
        return false;
    } else {
        multiplate = Head;
        point = Head->next;
        if (multiplate == point) { //если один элемент
            if (multiplate->number == a)
                return true;
            else return false;
        } else {
            while ((point->number != NULL) && (point->number != a)) {
                multiplate = point;
                point = multiplate->next;
            }
        } if (point->number == a) { // если нашли элемент, который больше добавляемого
            return true;
        } else if (point == NULL) { // если дошли до конца множества
            return false;
        }
    }
}

// объединение множеств
Set operator+ (Set s) {
    element *multuplate_1;
    element *Multiplate_2;
    Set result;
    // если одно из множеств пусто
    if (this->Head == NULL) {
        result = s;
        return result;
    } else if (s.Head == NULL) {
        result = *this;
        return result;
    } else { // если оба множества не пустые
        multuplate_1 = Head;
        Multiplate_2 = s.Head;
        while (multuplate_1 != Tail) {
            result + multuplate_1->number;
            multuplate_1 = multuplate_1->next;
        }
        result + multuplate_1->number;
        while (Multiplate_2 != s.Tail) {
            result + Multiplate_2->number;
            Multiplate_2 = Multiplate_2->next;
        }
        result + Multiplate_2->number;
    }
    return result;
}

// объединение множества и эл-та (добавление эл-та в мн-во)
Set operator+ (int a) {
    element* multiplate;
    element* point;
    Set result = *this;
    // если у нас пустое множество
    if (result.Head == NULL) {
        result.Head = new element;
        result.Head->number = a;
        result.Head->next = result.Head;
        result.Tail = result.Head;
        return result;
    } else {
        multiplate = result.Head;
        point = result.Head->next;
        if (multiplate == point) { //если один элемент
            point = new element;
            point->number = a;
            point->next = result.Head;
            multiplate->next = point;
            result.Tail = point;
            return result;
        } else {
            while (point != result.Head && (point->number < a)) {
                multiplate = point;
                point = point->next;
            }
            if (multiplate == result.Tail) { // если дошли до конца множества
                point = new element;
                point->number = a;
                multiplate->next = point;
                point->next = result.Head;
                result.Tail = point;
                return result;
            }
            else if (multiplate->number > a) { // если нашли элемент, который больше добавляемого
                result.Tail->next = new element;
                result.Tail->next->number = a;
                result.Tail->next->next = multiplate;
                result.Head = result.Tail->next;
                return result;
            } else if (point->number > a && a != result.Head->number) { // если нашли элемент, который больше добавляемого
                multiplate->next = new element;
                multiplate->next->number = a;
                multiplate->next->next = point;
                return result;
            }
            if (point->number > a && a == result.Head->number)
                return result;
            if (point->number == a) {
                return result;
            }
        }

    }
}

// объединение эл-та и мн-ва (добавление эл-та в мн-во)
friend Set operator+ (int a, Set& s) {
    return s + a;
}

// исключение множества из другого множества
Set operator- (Set s) {
    element *cur1;
    element *cur2;
    Set intersection;
    // если одно из множеств пусто
    if (this->Head != NULL && s.Head == NULL) {
        intersection = s + *this;
    } else
    if (this->Head == NULL) {
        intersection = *this;
    }
    else { // если оба множества не пустые
        cur1 = Head;
        cur2 = s.Head;
        while (cur1 != Tail) {
            intersection + cur1->number;
            cur1 = cur1->next;
        }
        intersection + cur1->number;
        while (cur2 != s.Tail) {
            intersection - cur2->number;
            cur2 = cur2->next;
        }
        intersection - cur2->number;
    }
    return intersection;
}

// исключение элемента из множества (удаление эл-та)
int operator- (int a) {
    element* multiplate;
    element* point;
    // если у нас пустое множество
    if (Head == NULL)
        return 0;
    else {
        multiplate = Head;
        point = Head->next;
        if (multiplate == point) { //если один элемент
            if (multiplate->number == a) {
                delete multiplate;
                Head = NULL;
                Tail = NULL;
                return 1;
            } else return 0;
        } else {
            if (multiplate->number == a) { // удаление первого эл-та
                Tail->next = point;
                Head = point;
                delete multiplate;
                return 1;
            }
            while (point != NULL && (point->number != a)) {
                multiplate = point;
                point = point->next;
            }
            if (point->number == a) { // если нашли элемент, который больше добавляемого
                multiplate->next = point->next;
                if (point == Tail)
                    Tail = multiplate;
                delete point;
                return 1;
            } else if (point == Head) { // если дошли до конца множества
                return 0;
            }
        }
    }
}

// длина множества
int length () {
    if (Head == NULL)
        return 0;
    element* cur1 = Head;
    element* cur2 = cur1->next;
    int count = 0;
    if (cur1 == cur2)
        return 1;
    else {
        count += 1;
        while (cur2 != Head) {
            cur1 = cur2;
            cur2 = cur1->next;
            count += 1;
        }
        return count;
    }
}

// вывод множества
friend ostream &operator<<(ostream &out, Set s) {
    if (s.Head == NULL)
        out << "Множество пустое!" << endl;
    else {
        element *cur1 = s.Head;
        element *cur2 = cur1->next;
        if (cur1 == cur2) {
            out << "Размер множества: " << s.length() << endl;
            out << cur1->number << endl;
        }
        else {
            out << "Размер множества: " << s.length() << endl;
            while (cur2 != s.Head) {
                out << cur1->number << ' ';
                cur1 = cur2;
                cur2 = cur2->next;
            }
            out << cur1->number << endl;
        }
    }
}

~Set() {
    Head = NULL;
    Tail = NULL;
}
#include "Methods.h"
