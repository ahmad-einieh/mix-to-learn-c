#if !defined PUB
#define PUB

enum pubType
{
    Book,
    Magazien
};
enum CoverType
{
    HAARDCOVER,
    PAPERBACK
};
struct MagazineID
{
    int issn;
    int vol;
    int issue;
};
union pubId
{
    int issn;
    struct MagazineID magid;
};

struct publication
{
    enum pubType pType;
    char title[1000];
    int nPages;
    enum CoverType ctype;
    float price;
    union pubId id;
};

struct pubList
{
    int count;
    struct publication *list;
};

struct publication readpub();

int findpub(struct publication *, struct pubList);

struct pubList getallbooks(struct pubList);

#endif