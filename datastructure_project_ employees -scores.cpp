//
//ضع يدك قبل يدي لان يدك لا تخطىء
//
//
#include <iostream>
using namespace  std;

class Employee_Score {
    int *arr;
    int size;       // all places
    int length;       // busy places only
public:
    Employee_Score(int size) {            // constractor to set values
        this->size=size;
        length=0;
        arr=new int[size];
    }

    void fillAraayScore() {                //fill the first group of scores
        int numOfScores;
        cout<<"Enter the number of scores you have to fill now!! ";
        cin>>numOfScores;
        for (int i=0;i<numOfScores;i++) {
            cout<<"Score"<<i+1<<":";
            cin>>arr[i];
            length++;
        }
    }

    bool IsFull() {
        return length==size;
    }

    bool IsEmpty() {
        return length==0;
    }

    void addScore(int score) {
        if (IsFull()) {
        	cout<<"Size not enough "<<endl;
            return;                        // end
        }
        int i;
		for ( i=length-1;i>=0&& arr[i]>score;i--) {       // shift
		    arr[i+1]=arr[i];
		}
		arr[i+1]=score;                               // add in its correct place
		length++;
    }


    void sortScores() {                                        // bubble sort
        for (int i = 0; i < length - 1; i++) {                   // no need to the latest number
            for (int j = 0; j < length - i - 1; j++) {             // no need to the latest number comparason too
                if (arr[j] > arr[j + 1]) {                          // Swap
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

 	int GetSize(){
 		return(size);
 	}
	 int GetLength(){
 		return(length);
 	}

	void deleteScore (int score){
		bool exist=0;
		if(IsEmpty()){
			cout<<"you don't have any scores";
			return;
		}

		else{int index;
				for(int i=0;i<length;i++){

					if(arr[i]==score){
						index=i;
						length--;
						exist=1;
						break;
						}
					}


				if(exist==0){
					cout<<" ERROR! you don't have this score.\n";
				}
				else{
					for(int i=index;i<length;i++){
						arr[i]=arr[i+1];
					}
				}
		}
	}

	void display(){										 // display function
        for(int i=0;i<length;i++){
            cout<< arr[i]<<"\t ";
            }
        cout<<"\n";
    }
     int getMaxScore() {
        if (IsEmpty()) {
            cout << "No scores available.\n";
            return -1;
        }
        return arr[length - 1];
    }

    int getMinScore() {
        if (IsEmpty()) {
            cout << "No scores available.\n";
            return -1;
        }
        return arr[0];
    }

};
int main() {
  int total_number_of_score;
  cout<<"Enter the total number of Employee score you need"	<<endl;
  cin>>total_number_of_score;
  Employee_Score e( total_number_of_score);
    e.fillAraayScore();
    e.sortScores();
    cout<<"The scores that you have are : \n";
    e.display();
    string mak_add;
    cout<<"Do you want to make addation answer by(yes/no)"<<endl;
    cin>>mak_add;
    if(mak_add=="yes"){
    	int num_of_new_scors;
    	cout<<"Enter how many number you need to add "<<endl;
    	cin>>num_of_new_scors;
    	for (int i=0;i<num_of_new_scors;i++){
    	 int new_score;
         cout<<"Enter the new score you want to add"<<endl;
         cin>>new_score;
         e.addScore(new_score);
		}
		 cout<<"The scores that you have after addation  are : \n";
         e.display();

	}
	string mak_delet;
    cout<<"Do you want to make deletion answer by(yes/no)"<<endl;
    cin>>mak_delet;
    if(mak_delet=="yes"){
    	int num_of_deleted_scors;
    	cout<<"Enter how many number you need to delet"<<endl;
    	cin>>num_of_deleted_scors;
    	for (int i=0;i<num_of_deleted_scors;i++){
    		 int del_score;
    	     cout<<"Please enter the score you want to delete:\n";
           	 cin>>del_score;
	         e.deleteScore(del_score);
		}
			cout<<"The scores that you have after deletion are : \n";
         	e.display();
	}
	     cout<<"The size of arr after process = "<<e.GetSize()<<" & The length of arr after process  = "<<e.GetLength()<<endl;

	     cout << "Maximum score: " << e.getMaxScore() << endl;
         cout << "Minimum score: " << e.getMinScore() << endl;

}
