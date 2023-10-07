#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// hna 9adina wahd new data type kayjm3 smya o aswat dyal kola motarachih
typedef struct
{
    string name;
    int votes;
}
candidate;

// hna 9adina array bdak data type li gadina flfo9
candidate candidates[MAX];

// hna binbdaw nhsbo f l motarachihin
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // anchofo wach l user dkhl 3l a9al 2 motarachihin
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // anhsbo 3adad lmotarachihin bla manhsbo ./plurality
    candidate_count = argc - 1;

    // check if number of candidates bigger than 9
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // loop over all candidates to update their information argv[i + 1] bach manhsbo ./plurality
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // hna ghanshofo l user chhal mn sawt bgha
    int voter_count = get_int("Number of voters: ");

    // an3tiwh idkhl l candidates 3la hsab chhal mn votes bgha
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// hna fin ghanbdow nhsbo l aswat dyal kola candidates
bool vote(string name)
{
    // ghanlopiw 3la kola condidate o nchekiw ila kan inpur dyal user mtab9 m3a smit condidate bach vote++
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    // hna ila maknch l input mtab9 m3a hta name
    return false;
}

// hna ghadi nbdw nprintiw smyat dyal l candidates li rbho
void print_winner(void)
{
    // hna 9adina variable 3la assas hiya ghatakhd lina akbar num dyal lvotes
    int winner_votes = 0;

    // hna ghanlopiw 3la ga3 l condidats votes bch akbar value n3tiwha l variabla dyalna
    for (int i = 0; i < candidate_count; i++)
    {
        // hna votes dyal lcondidates ayt3ta l variable dyalna
        if (winner_votes < candidates[i].votes)
        {
            winner_votes = candidates[i].votes;
        }
    }

    // hna ghanbdaw n9arno bin l value dyal variable dyalna bach nchofo ga3 l condidates li 3ndhoum akbar value
    for (int i = 0; i < candidate_count; i++)
    {
        if (winner_votes == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}