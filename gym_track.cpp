#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class GymTrack{

	public:
		GymTrack(){
			cout<< "Intializing the object"<<endl;
		}
		~GymTrack(){
			cout<<"Deleting the object"<<endl;
		}


	protected:
		vector<int> count_per_exercise;
		vector<string> exercise_names;

	
};


class GymTrackInterface: public GymTrack{

	public:
		string trainee;
		GymTrackInterface(string trainee_name): GymTrack(){
		       trainee = trainee_name;
	       	       cout << "Intialized the trainee " << trainee << endl;
		}	       
		
		void exercise_counter(string done_exercise){
		
			auto it = find(exercise_names.begin(), exercise_names.end(), done_exercise);
			if (it != exercise_names.end()){
				int index = distance(exercise_names.begin(), it);
				cout<< "Exercise at index: " << index << endl;
				count_per_exercise[index] += 1;
			}
			else{
				exercise_names.push_back(done_exercise);
				count_per_exercise.push_back(1);
			}


		}


		void print_exercise(){
		
			for (int i=0; i< exercise_names.size(); i++){
				
				cout<< exercise_names[i] << " and its count "<< count_per_exercise[i] << endl;	
		
			}
		}




};




int main(){



	GymTrackInterface gym_sha("Shashank");	
	
	gym_sha.exercise_counter("leg_curl");

	gym_sha.exercise_counter("leg_extension");

	gym_sha.exercise_counter("leg_curl");

	gym_sha.print_exercise();



	return 0;
}
