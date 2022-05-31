#include "musicians.h"
std::string Song::get_song_name()const
{
  return m_song_name;
}
int Song::get_date_of_issue() const
{
  return m_date_of_issue;
}
std::string Song::get_issuer_name()const
{
	return m_issuer_name;
}
int Song::get_song_duration() const
{
  return m_song_duration;
}
bool Song::get_favorite_flag() const
{
  return m_favorite_flag;
}
void Song::set_favorite_flag()
{
  m_favorite_flag = !m_favorite_flag;
}
void Song::print_song_info()
{
  std::cout << "Song(" << m_song_name << ", "
                      << m_date_of_issue << ", "
                      << m_issuer_name << ", "
                      << m_song_duration << ")-";
  if(get_favorite_flag()){
    std::cout << "in favorite" << std::endl;
  }else {
    std::cout << "in cloud" << std::endl;
  }
}
Musician::~Musician()
{
  for (int i = 0; i < m_songs.size(); ++i){
    delete m_songs[i];
  }
}
std::string Musician::get_name() const
{
  return m_name;
}
std::string Musician::get_country() const
{
  return m_country;
}
int Musician::get_date_of_birth()  const
{
  return m_date_of_birth;
}
bool Musician::get_favorite_flag() const
{
  return m_favorite_flag;
}
void Musician::set_favorite_flag()
{//փոխում է flag-ը
  m_favorite_flag = !m_favorite_flag;
}
void Musician::print_musician_info()
{
  std::cout << "Musician(" << m_name << ", "
                          << m_country << ", "
                          << m_date_of_birth << ")-";
  if(m_favorite_flag){
    std::cout << "in favorite" << std::endl;
  }else {
    std::cout << "in cloud" << std::endl;
  }
}
void Musician::add_songs(Song* obj)
{
	if (obj->get_song_name() == m_name){
		m_songs.push_back(obj);
	}
}
void select_next_step()
{
	std::cout << "anything else?\n___\b\b";
	int number;
	std::cin >> number;
	if (number >= 1 && number <= 9){
		choose_function(number);
	}else{
		std::cout << "your input is not correct. Please, input numbers from diapazone [1;9]";
	}
}
void print_steps()
{
	int step;
	std::cout << "enter '1'---to add new song in cloud\n"
	  				<< "enter '2'---to add new  musician in cloud\n"
						<< "enter '3'---to add song to favorites\n"
						<< "enter '4'---to add musician to favorites\n"
						<< "enter '5'---to remove song from favorites\n"
						<< "enter '6'---to remove musician from favorites\n"
						<< "enter '7'---to search song\n"
						<< "enter '8'---to search musician\n"
						<< "enter '9'---to exit from program\n"
						<< "your choose: ___\b\b";
	std::cin >> step;
	choose_function(step);
}
void add_musician(Musician& obj)
{
  musicians_in_cloud.push_back(&obj);
}
void add_song(Song& obj)
{
	songs_in_cloud.push_back(&obj);
}
void add_song_to_favorite(std::string song_title)
{
  for (int i = 0; i < songs_in_cloud.size(); ++i){//փնտրել երգերի բազայում
    if (song_title == songs_in_cloud[i]->get_song_name()){//եթե գտնվել է նման վերնագրով երգ
      songs_in_favorite.push_back(songs_in_cloud[i]);//ավելացնել ֆավորիտների մեջ
			songs_in_cloud[i]->set_favorite_flag();//երգի ֆլագը միացնել
			songs_in_cloud.erase(songs_in_cloud.begin() + i);//ջնջել cloud-ից
			std::cout << "Song added in favorites\n";//տեղեկացնել, որ գործողությունն արված է
			select_next_step();
    }
	}//եթե բազայում չկա նման անունով երգ
	for (int i = 0; i < songs_in_favorite.size(); ++i){//փնտրել ֆավորիտների բազայում
    if (song_title == songs_in_favorite[i]->get_song_name()){//եթե գտնվել է նման վերնագրով երգ
			std::cout << "The song is already in favorites\n";
			select_next_step();
		}
	}//եթե այստեղ էլ չկա
  std::cout << "The song was not found\n";//տեղեկացնել
	select_next_step();
}
void add_musician_to_favorite(std::string name)
{
  for (int i = 0; i < musicians_in_cloud.size(); ++i){//փնտրել երաժիշտներիրի բազայում
    if (name == musicians_in_cloud[i]->get_name()){//եթե գտնվել է նման անունով երաժիշտ
      musicians_in_favorite.push_back(musicians_in_cloud[i]);//ավելացնել ֆավորիտների մեջ
			musicians_in_cloud[i]->set_favorite_flag();//երաժիշտի ֆլագը միացնել
			musicians_in_cloud.erase(musicians_in_cloud.begin() + i);//ջնջել cloud-ից
      std::cout << "musician added in favorites\n";//տեղեկացնել, որ գործողությունն արված է
      select_next_step();
    }
	}//եթե բազայում չկա նման անունով երաժիշտ
  for (int i = 0; i < musicians_in_favorite.size(); ++i){//փնտրել ֆավորիտների բազայում
    if (name == musicians_in_favorite[i]->get_name()){//եթե գտնվել է նման վերնագրով երգ
			std::cout << "The musician is already in favorites\n";
			select_next_step();
		}
	}//եթե այստեղ էլ չկա
  std::cout << "The musician was not found\n";//տեղեկացնել
	select_next_step();
}
void create_song()
{
	std::cout << "Input the song title: ";
  std::string title;
  std::cin >> title;
  std::cout << "now input the date of issue: ";
  int date;
  std::cin >> date;
  std::cout << "issuer name: ";
  std::string name;
  std::cin >> name;
  std::cout << "song duration: ";
  int duration;
  std::cin >> duration;
  Song obj{title, date, name, duration};
	add_song(obj);
	std::cout << "Do you want to add to favorites this song? /y or n\n";
	std::string answer;
	do{
      std::cin >> answer;
      if (answer != "y" && answer != "n"){
        std::cout << "your input is not correct. Please, enter \'y\' or \'n\'";
      }
  }while(answer != "y" && answer != "n");
	if (answer == "n"){
		std::cout << "OK!\n";
		select_next_step();
	}
	add_song_to_favorite(title);
}
void create_musician()
{
	std::cout << "Input the musician name: ";
	std::string name;
  std::cin >> name;
  std::cout << "country: ";
  std::string country;
  std::cin >> country;
  std::cout << "date of birth: ";
  int date;
  std::cin >> date;
  Musician obj{name, country, date};
  add_musician(obj);
	std::cout << "Do you want to add to favorites the musician? /y or n\n";
	std::string answer;
	do{
    std::cin >> answer;
    if (answer != "y" && answer != "n"){
      std::cout << "your input is not correct. Please, enter \'y\' or \'n\'";
    }
  }while(answer != "y" && answer != "n");
	if (answer == "n"){
		std::cout << "OK!\nanything else?\n";
		select_next_step();
	}
	add_musician_to_favorite(name);
}
void search_song(std::string song_title)//ստանում է երգի վերնագիրը,տպում է նկարագրությունը
{
	for (int i{}; i < songs_in_cloud.size(); ++i){
    if (song_title == songs_in_cloud[i]->get_song_name()){//եթե գտնվել է տվյալ վերնագրով երգ
      songs_in_cloud[i]->print_song_info();//տպել երգի մասին ինֆորմացիան
      select_next_step();
    }
  }//եթե cloud-ում չի գտնվել, փնտրում ենք favorite-ի մեջ
  for (int i{}; i < songs_in_favorite.size(); ++i){
    if (song_title == songs_in_favorite[i]->get_song_name()){//եթե գտնվել է տվյալ վերնագրով երգ
      songs_in_favorite[i]->print_song_info();//տպել երգի մասին ինֆորմացիան
      select_next_step();
    }
  }//եթե ոչ մի տեղ չկա երգը,
  std::cout << "Not found!!\n";//հայտնել
  std::cout << "Are you want to crate new song?/y or n\n";
  std::string answer;
  do{
  	std::cin >> answer;
    if (answer != "y" && answer != "n"){
      std::cout << "your input is not correct. Please, enter \'y\' or \'n\'\n";
    }
  }while(answer != "y" && answer != "n");
	if(answer == "n"){
		select_next_step();
	}
  create_song();
}
void search_musician(std::string name)//ստանում է երաժիշտի անունը,տպում է նրա մասին ինֆորմացիան
{
	for (int i{}; i < musicians_in_cloud.size(); ++i){
    if (name == musicians_in_cloud[i]->get_name()){//եթե գտնվել է տվյալ անունով երաժիշտ
      musicians_in_cloud[i]->print_musician_info();//տպել երաժիշտի մասին ինֆորմացիան
      select_next_step();
    }
  }//եթե cloud-ում չի գտնվել, փնտրում ենք favorite-ի մեջ
  for (int i{}; i < musicians_in_favorite.size(); ++i){
    if (name == musicians_in_favorite[i]->get_name()){//եթե գտնվել է տվյալ անունով երաժիշտ
      musicians_in_favorite[i]->print_musician_info();//տպել երաժիշտիի մասին ինֆորմացիան
      select_next_step();
    }
  }//եթե ոչ մի տեղ չկա երգը,
  std::cout << "Not found\n";//հայտնել
	std::cout << "Are you want to crate new musician?/y or n\n";
  std::string answer;
  do{
      std::cin >> answer;
      if (answer != "y" && answer != "n"){
        std::cout << "your input is not correct. Please, enter \'y\' or \'n\'\n";
      }
  }while(answer != "y" && answer != "n");
	if(answer == "n"){
		select_next_step();
	}
  create_musician();
}
void remove_song_from_favorite(std::string song_title)
{
  for (int i = 0; i < songs_in_favorite.size(); ++i){//փնտրել երգերի բազայում
    if (song_title == songs_in_favorite[i]->get_song_name()){//եթե գտնվել է նման վերնագրով երգ
			songs_in_cloud.push_back(songs_in_favorite[i]);
      songs_in_favorite.erase(songs_in_favorite.begin() +i);//ջնջել ֆավորիտների միջից
      songs_in_favorite[i]->set_favorite_flag();//երգի ֆլագը անջատել
      std::cout << "The song removed from favorites\n";//տեղեկացնել, որ գործողությունն արված է
			select_next_step();
    }
  }//եթե բազայում չկա նման անունով երգ
	std::cout << "The song was not found in favorites\n";//տեղեկացնել
	select_next_step();
}
void remove_musician_from_favorite(std::string name)//հանում է երաժիշտին ֆավորիտների միջից
{
  for (int i = 0; i < musicians_in_favorite.size(); ++i){//փնտրել երաժիշտների բազայում
    if (name == musicians_in_favorite[i]->get_name()){//եթե գտնվել է նման երաժիշտ
      musicians_in_favorite[i]->set_favorite_flag();//անջատել flag-ը
      musicians_in_cloud.push_back(musicians_in_favorite[i]);//ավելացնում ենք cloud-ի մեջ
      musicians_in_favorite.erase(musicians_in_favorite.begin() + i);//ջնջում ենք ֆավորիտների միջից
			std::cout << "The musician removed from favorites\n";
      select_next_step();
    }
  }//եթե բազայում չկա նման անունով երաժիշտ
  std::cout << "The musician was not found in favorites\n";//տեղեկացնել
	select_next_step();
}
void choose_function(int key)
	{
		switch(key){
			case 1: {create_song();}
				break;
			case 2: {create_musician();}
				break;
			case 3: {std::cout << "Please, input the song title\n";
				std::string title;
				std::cin >> title;
				add_song_to_favorite(title);}
				break;
			case 4: {std::cout << "Please, input the name\n";
				std::string name;
				std::cin >> name;
				add_musician_to_favorite(name);}
				break;
			case 5: {std::cout << "Please, input the song title\n";
				std::string title;
				std::cin >> title;
				remove_song_from_favorite(title);}
				break;
			case 6: {std::cout << "Please, input the name\n";
				std::string name;
				std::cin >> name;
				remove_musician_from_favorite(name);}
				break;
			case 7: {std::cout << "Please, input the song title\n";
				std::string title;
				std::cin >> title;
				search_song(title);}
				break;
			case 8: {std::cout << "Please, input the name\n";
				std::string name;
				std::cin >> name;
				search_musician(name);}
				break;
			case 9: {std::cout << "are you sure, you really want to exit from program?/'y' or 'n' \n";
				std::string key;
				do {
						std::cin >> key;	
					if (key != "y" && key != "n"){
						std::cout << "your input is not correct. Please, input 'y' or 'n'\n";	
					}
				}while(key != "y" && key != "n");				
				if(key == "y"){
					std::cout << "bye!!!!!";
					exit(0);
				}else if(key == "n"){
					select_next_step();					
					}
				}
			default :{std::cout << "your input is not correct. Please, input numbers from diapazone [1;9]";
					select_next_step();}	
			}
}
int main(){
	Musician obj("Beatles","England", 1958);
	add_musician(obj);
  Musician obj2("Aznavour","France", 1924);
	add_musician(obj2);
  Musician obj3("Shakira","Brazil", 1977);
	add_musician(obj3);
  Song song("Yesterday", 1965, "Beatles", 323);
	add_song(song);
	Song song1("loca", 2008, "Shakira", 230);
	add_song(song1);
	Song song2("She", 1992, "Aznavour", 280);
	add_song(song2);
	Song song3("Girl", 1975, "Beatles", 220);
	add_song(song3);
	
	std::cout << "Wellcome to audiosearch program\n\n";
	print_steps();
	
	return 0;
}
