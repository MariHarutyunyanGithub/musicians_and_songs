#include <iostream>
#include <vector>
class Song
{
public:
  Song(){};
  Song(std::string song_name, int date_of_issue, std::string issuer_name, int song_duration)												:m_song_name{song_name}
                      		       	,m_date_of_issue{date_of_issue}
                                          ,m_issuer_name{issuer_name}
                                          ,m_song_duration{song_duration}{};
  ~Song(){}
public:
  std::string get_song_name()const;
  int get_date_of_issue() const;
  std::string get_issuer_name()const;
  int get_song_duration() const;
  bool get_favorite_flag() const;
	void set_favorite_flag();
	void print_song_info();
private:
  std::string m_song_name{};
  int m_date_of_issue{};
  std::string m_issuer_name{};
  int m_song_duration{};
  bool m_favorite_flag{};
};
class Musician
{
public:
  Musician(){}
  Musician(std::string name, std::string country, int date_of_birth)
                                         :m_name{name}
                                         ,m_country{country}
                                         ,m_date_of_birth{date_of_birth}{}
	~Musician();
	std::string get_name() const;
	std::string get_country() const;
	int get_date_of_birth()  const;
	bool get_favorite_flag() const;
	void set_favorite_flag();//փոխում է flag-ը
	void print_musician_info();
	void add_songs(Song* obj);
private:
  std::string m_name{};
  std::string m_country{};
  int m_date_of_birth{};
  bool m_favorite_flag{};
	std::vector<Song*> m_songs;
};
std::vector<Musician*> musicians_in_cloud;
std::vector<Song*> songs_in_cloud;
std::vector<Musician*> musicians_in_favorite;
std::vector<Song*> songs_in_favorite;
void choose_function(int);
void select_next_step();
void print_steps();
void add_musician(Musician& obj);
void add_song(Song& obj);
void add_song_to_favorite(std::string song_title);
void add_musician_to_favorite(std::string name);
void create_song();
void create_musician();
void search_song(std::string song_title);
void search_musician(std::string name);		
void remove_song_from_favorite(std::string song_title);
void remove_musician_from_favorite(std::string name);
void choose_function(int key);
