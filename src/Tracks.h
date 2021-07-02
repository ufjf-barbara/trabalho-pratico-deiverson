#ifndef TRACKS_H_INCLUDED
#define TRACKS_H_INCLUDED

using namespace std;

struct tracks
{
    string id;
    string name;
    int popularity;
    float duration_ms;
    int explicit_;
    string artists;
    string id_artists;
    string release_date;
    float danceability;
    float energy;
    int key;
    float loudness;
    int mode;
    float speechiness;
    float acousticness;
    float instrumentalness;
    float liveness;
    float valence;
    float tempo;
    int time_signature;
};
struct tracksAux
{
    char id[48];
    char name[386];
    int popularity;
    float duration_ms;
    int explicit_;
    char artists[939];
    char id_artists[1511];
    char release_date[1434];
    float danceability;
    float energy;
    int key;
    float loudness;
    int mode;
    float speechiness;
    float acousticness;
    float instrumentalness;
    float liveness;
    float valence;
    float tempo;
    int time_signature;
};

class Tracks
{

private:
    list<tracks> lista;

public:
    Tracks(string path);
    Tracks();
    ~Tracks();

    list<tracks> getList();

    //METODOS
    void leArquivo(string path);
    void TransformaTrackBin();
    tracksAux converteToAux(tracks tr);
    static tracks converteTracksToString(tracksAux tr);
    static string concatenaTracks(char linha[]);

    //METODOS estaticos
    static bool verifica_numero(int vet[], int n, int aux);
    static void sorteia_numero(int vet[], int n, int qtddReg);
    static vector<tracks> registrosTr(int n,int tam);

    // contadores estaticos
    int id;
    int name;
    int artists;
    int id_artists;
    int release_date;
};

#endif // TRACKS_H_INCLUDED
