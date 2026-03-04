#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <memory>


class Item {
   private:
    std::string name_;
    int value_;

   public:
    Item(const std::string& name, int value) : name_(name), value_(value) {}
	 
	 //Item() : value_(-1) {}
	 //c++ 11 + tol (prob cpp14)
	 //Item() = default;
	 //ketto egyben best practice
	 Item() : name_(""), value_(-1) = default;
    const std::string& getName() const { return name_; }
    int getValue() const { return value_; }

	 ~Item(){
		  std::cout << "Item with value" << value_ << "destroyed" << '\n';
	 }
};

class Inventory {
   private:
	 //Item** items_; 1. verzio
	 //std::unique_ptr<Item>* items_;
	 //leetne <Item*[]> de a -1 inrekcios szint itt most mind1
	 std::unique_ptr<Item[]> items_;
	 
    int capacity_;
    int count_;

   public:
    Inventory(int capacity) : capacity_(capacity), count_(0) {
       // items_ = new std::unique_ptr<Item>[capacity_];
        items_ = std::make_unique<Item[]>(capacity_);
		  /*
        for (int i = 0; i < capacity_; i++) {
            items_[i] = nullptr;
        }*/
    }

    ~Inventory() {
		  /*
        for (int i = 0; i < count_; i++) {
            delete items_[i];
        }*/
        //ez meg std::unique_prt<Item>item* hez kellett 
		  //delete[] items_;
    }

    bool addItem(const std::string& name, int value) {
        if (count_ >= capacity_) {
            std::cout << "✗ Inventory full! Cannot add: " << name << "\n";
            return false;
        }

        items_[count_] =  std::make_unique<Item[]>(name, value);
        count_++;
        std::cout << "✓ Added: " << name << " (value: " << value << ")\n";
        return true;
    }

    bool removeItem(const std::string& name) {
        for (int i = 0; i < count_; i++) {
				//nullptr check - a legutobbi smrt_ptr miatt miatt
            if ( items_[i].getName() == name) {
                //delete items_[i];

                // Shift remaining items
                for (int j = i; j < count_ - 1; j++) {
                    items_[j] =std::move(items_[j + 1]);
                }
					 //ez kell meg maradjon mert majd meg lolul kell irni
                //items_[count_ - 1] = nullptr; nem kell smrt_ptr miatt
                count_--;

                std::cout << "✓ Removed: " << name << "\n";
                return true;
            }
        }

        std::cout << "✗ Item not found: " << name << "\n";
        return false;
    }

    void display() const {
        std::cout << "\nCurrent inventory (" << count_ << "/" << capacity_ << " items):\n";
        if (count_ == 0) {
            std::cout << "  (empty)\n";
            return;
        }

        for (int i = 0; i < count_; i++) {
            if (items_[i] != nullptr) {
                std::cout << "  " << (i + 1) << ". " << std::left << std::setw(20)
                          << items_[i].getName() << " - " << items_[i].getValue() << " gold\n";
            }
        }
    }

    int getCount() const { return count_; }
    int getCapacity() const { return capacity_; }
};
