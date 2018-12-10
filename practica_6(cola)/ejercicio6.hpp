#ifndef TCARTA_H
#define TCARTA_H

enum tPalo {OROS,COPAS,BASTOS,ESPADAS};
enum tFig {AS,DOS,TRES,CUATRO,CINCO,SEIS,SIETE,SOTA,CABALLO,REY};

class tCarta{
    public:
        tCarta(tPalo p = OROS, tFig f = AS) : palo_(p), fig_(f) {};
        tPalo palo() const { return palo_; };
        tFig fig() const { return fig_; };
        friend std::ostream& operator <<(std::ostream& os, const tCarta& c);
    private:
        tPalo palo_;
        tFig fig_;
        static const char* nom_palo[], * nom_fig[];
};
#endif