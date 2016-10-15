// Pekka Pirila's sports timekeeping program (Finnish: tulospalveluohjelma)
// Copyright (C) 2015 Pekka Pirila 

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef LASKENT_H_DEFINED
#define LASKENT_H_DEFINED

#include <stdio.h>
#include <time.h>
#include "VDef.h"
#include <xmlparser.h>
#ifdef _CONSOLE
#else
#include "WinTp.h"
#include "VWinDef.h"
#endif

void kirjloki(char *msg);
void wkirjloki(wchar_t *msg);
void lopetus(void);
wchar_t *Build(void);
wchar_t *VersioNo(void);
int VersioInt(void);
void setBrowserEmulation(void);
void getWinVersion(void);

wchar_t XMLhaetunnus(wchar_t *Nimi, wchar_t *Koodit, wchar_t **Nimet, int N);
wchar_t *XMLhaeteksti(wchar_t Koodi, wchar_t *Koodit, wchar_t **Nimet);
int XMLhae_tagid(wchar_t *Tag, tagListTp *Tags, UINT nTags);
wchar_t *XMLhae_tagName(int tagid, tagListTp *Tags, UINT nTags);
void XMLhaenodeid(xml_node *node, int nnode, tagListTp *Tags, UINT nTags);

wchar_t *wcstokch(wchar_t *st, wchar_t erotin);
int parametrivirhe(wchar_t *sub, int intparam, wchar_t *strparam, wchar_t charparam);
char *keyfromU8name(char *key, char *name, int len, int flags);
char *keyfromU16name(char *key, wchar_t *name, int len, int flags);
char *osuuskoodi(int sarja, int os, char *kdi, int len);
wchar_t *wosuuskoodi(int sarja, int os, wchar_t *kdi, int len);
int tulkOsuuskoodi(int sarja, wchar_t *st);
int inputosuus(int *osuus, int sarja, int len, int x, int y, wchar_t *opts, wchar_t *tc);
int sarjaKno(int kilpno);
void poistaindeksi(kilpindex *ind);
void PUTREC(kilptietue *kilp, int d);
void GETREC(kilptietue *kilp, int d);
INT getpos(INT kilpno);
INT setpos(INT kno, int d);
int haeSeurVapaaKno(int alku);
void tallKnoSiirto(int sarja, int siirto, int kielto);
void kirjKilpSQL(int d);
int JarjSeur(int yhd, int osuus, int piste, int dKilp);
void SetJarjSeur(int yhd, int osuus, int piste, int dKilp, int jp);
int askellasarja(int srj, int osuus, int *aos, int piste, int p, int *lj);
int JarjTulos(int yhd, int os, int piste, int dKilp);
int OsJarjSeur(int yhd, int srj, int *osseur, int dKilp);
void SetOsJarjSeur(int yhd, int srj, int osuus, int dKilp, int jp);
int JarjOsTulos(int yhd, int os, int dKilp);
INT va_piste(INT piste);
wchar_t *str_piste(int piste);
int JosAlku(int srj, int os, int *aos);
void setJosAlku(int srj, int aos, int jp);
int haesarja(char *snimi, bool salliyhd);
int haesarja_w(wchar_t *snimi, bool salliyhd);
INT entsija(INT d, INT *p, int osuus, INT piste, INT yhd, int *keskeyta);
INT entossija(INT d, INT *p, int srj, int osuus, int *osseur, INT yhd, int *keskeyta);
int teejarj(void);
void lukumaarat(void);
void vidint2(int y, int x, int l, long i);
void putintright(int i, char *p);
char *poista_viiva(char *stout, char *stin, int size);
void help(int ih);
void tausta(int spoolfl);
void remtimer(void);
void tulaset_show(void);
void tuloslist(char kohde, char tiedlaji, char tulostettava, char jarjestys,
   int pisteval, int osuus, char rajaus, int alaraja, int ylaraja, int *sarjat,
   char *kohdenimi);
void clearframe63(void);
char *savescr(int r0, int c0, int r1, int c1);
void restorescr(int r0, int c0, int r1, int c1, char *buf);
void kehys(int kl);
void copydfile(datafile *datfb, int oldfile);
char *keyname(kilptietue *kilp);
int teeindeksi(kilpindex *ind, bool uusi);
int pyoristatls(int tls, int pyorista);
INT32 osuuslahto(kilptietue *kilp, int osuus);
INT32 tulos(kilptietue *kilp, int osuus, int va);
INT32 ttulos(kilptietue *kilp, int tosuus, int va, int lisafl);
INT32 osuustulos(kilptietue *kilp, int osuus, int va);
__int64 jtulos(kilptietue *kilp, int osuus,int va);
INT32 oslahto(kilptietue *kilp, INT osuus);
int KarkiTulos(int sarja, int os, int piste);
void merk_sijat(int sarja, int osuus, int va, int sija);
void prop_sulj(kilptietue *kilp, int osuus);
void haesija(kilptietue *kilp, int osuus, INT piste, INT yhd, int *keskeyta);
INT intsija(__int64 tl, INT *p, int osuus, INT piste, INT yhd, int *keskeyta);
int psija(int kno, int srj, int os, int va);
void merk_kilp_yl(kilptietue *kilp, int osuus);
void merk_yl(kilptietue *kilp);
void merk_yht_lahdot(int srj, bool nayta);
void paivJoukkLkm(int srj, int muutos);
void addjarjarr(kilptietue *kilp, int d, int osuus, INT piste, int *keskeyta);
void remjarjarr(kilptietue *kilp, int d, int osuus, INT piste, int *keskeyta);
void paivjarjarr(int srj);
INT getpos(INT kno);
void getrec_1(kilptietue *kilp, INT d);
void putrec_1(kilptietue *kilp, INT d);
void getrec_i(datafile *datf, int d, kilptietue *kilp);
void putrec_i(datafile *datf, int d, kilptietue *kilp);
void asetukset(void);
void lahetasulku(char *tn, INT kielto);
int aloitus(int argc, wchar_t *argv[], wchar_t *cfgflnm);
void kirj_err_file(char *msg, int nayta);
void kirj_err_file_w(wchar_t *wmsg, int nayta);
void outkilp(kilptietue *kilp, int osuus);
int find(int *d, kilptietue *kilp, int *osuus);
void korjaa(int d, kilptietue *kilp, int *osuus, int tausta,
   kilptietue *entkilp);
void tallenna(kilptietue *ekilp, int d, int tarbuffl, int kielto,
   int pakota_os, kilptietue *entkilp);
void autotulostus(void);
void merkisto(char merkit);
void laskenta(void);
void addtall(kilptietue *kilp, int *dataf, int kielto);
void deltall(int d, int kielto);
void korjaukset(void);
void puuttuvat(char **paika, int *psija, int srj);
void valikko(void);
int normtt(int t);
INT32 normkello_a(INT32 t);
INT32 normtulos_a(INT32 t);
void writeaika(int ino, int p);
void writeajat(void);
void suljeajat(int s_ino, bool delfl);
void haeAktAjat(int ino);
void laheta(int dkilp, int entno, int os, int piste, int comtarfl, int kielto,
   UINT32 luokka, int pakota_lah);
void lue_muotoilu(wchar_t *luetfnm, int kysy);
int lue_muotoilu_fl(char *luetfnm, int uusi);
void tall_muotoilu_fl(char *luetfnm);
void tall_muotoilu(wchar_t *luetfnm);
bool mahtuusivulle(int l, int vm, tulostusparamtp *tulprm);
int initcom(int cn);
void modemctrl(void);
void inittimer(void);
void aseta_s4(void);
void prscr(scr *s);
void spoolstatus(void);
int Nyt(void);
int tm_date(int t);
int tm_copydate(int ut, int vt, int vdate);
__int64 datetime64(aikatp *tm);
wchar_t *time_t_date(time_t t, wchar_t *dstr);
time_t date_time_t(wchar_t *st);
int  tall_rivi(int ino, aikatp *utm, aikatp *vtm, int *uptr,
   int kysy, int kielto, int pakota_lah);
//void poistarivi(int rtm, int ino);
//int  tall_kno(int ino, int rtm, int kno, int osuus);
//int  tall_aika(int ino, int wtm, TMAALI t);
int lisaa_aika(int ino, TMAALI t, int piste, int ed_t, int ed_date);
int  poista_aika(int ino, aikatp *rtm);
void AjatTiedostoon(wchar_t *fname, int akttm);
void AjatTiedostosta(wchar_t *fname, int akttm, bool vainajat);
void laheta_aika(aikatp *dtm, aikatp *itm, int kielto,
   int pakota_lah);
aikatp *gettm(int rvno, aikatp *raika, int ino);
aikatp *puttm(int rvno, aikatp *raika, int ino);
void paivita_aikanaytto(void);
void SiritSync(bool set_time);
int haeseurosuus(kilptietue *kilp);
int haeseurpiste(kilptietue *kilp, int os);
int yhtjono(int cn, int ino);
int lahettamatta(int cn);
INT32 purajak(INT32 tjak);
void laheta_yl(int sarja, int kielto);
void laheta_laskuri(int maali, int kielto);
void laheta_valmis(int maali, int osuus, TMAALI tv, int kielto);
void laheta_lahest(int lahpiste, int kno, long t, int muutos, int kielto);
void laheta_emva(kilptietue *kilp, int os);
void lahetakello(int cn, INT kielto);
int lah_tiedosto(wchar_t *tiednimi, int kielto, int flags);
void kirjemvaloki(combufrec *ibuf);
void tark_tiedosto(INT cn);
void kirjsarjat(void);
void putfld(tulostusparamtp *tulprm, wchar_t *str, INT pos, INT len, INT oik, INT r);
void endline(tulostusparamtp *tulprm, int n);
void newline(tulostusparamtp *tulprm, int n);
void endpage(tulostusparamtp *tulprm);
void enddoc(tulostusparamtp *tulprm);
void abortdoc(tulostusparamtp *tulprm);
void initline(tulostusparamtp *tulprm);
int initpage(tulostusparamtp *tulprm, const wchar_t *fnt);
int luesarja(char *snimi, char *ch);
int tulostasarja(INT *srj, tulostusparamtp *tulprm, INT *l, INT *sv, INT autotl);
int openport_x(int cn, int portti, int baud, char parity, int bits, int sbits, int xonoff);
void opencomRS(int cn);
void openlukijaUDP(int cn);
int openlukijaTCP(int cn);
int quesize_x(int cn, int *que);
void outquesize_x(int cn, int *que);
void o_flush_x(int cn);
void i_flush_x(int cn);
int read_ch_x(int cn, char *ch, int *que);
int wrt_ch_x(int cn, char ch);
int read_st_x(int cn, int len, char *buf, int *nread, int *que);
int wrt_st_x(int cn, int len, char *buf, int *nsent);
int closeport_x(int cn);
int wrt_st_x_srv(int cn, int len, char *buf, int *nsent);
void laheta_kello(INT cn);
void tark_kello(INT cn);
void closecom(void);
void merk_uusinta(int cna, int cny, long ta, long ty, int autouusinta);
void closetv(void);
void closetaulu(void);
void lahetaMonitorille(int yhtlkm, int yhtavattu, int jonossa, int jonoja);
void ajanotto(void);
int tallva(TMAALI aika, int os, int vali, int kno, int kielto, int pakota_lah);
//void add_va_jarj(kilptietue *kilp, int osuus, int va, int dkilp);
//void kirj_valiajat(int srj, int os, int va);
INT bdg2kno(INT32 badge, int *toinen);
void aseta_mtr(void);
ratatp *getrata(char *tunnus);
ratatp *getrata(wchar_t *tunnus);
int getratano(char *tunnus);
int getratano(wchar_t *tunnus);
int EmitJarr(int kilpno, int os);
void setEmitJarr(int kilpno, int os, int ep);
INT getem(emittp *em, INT kilpno, INT os);
INT putem(emittp *em, INT32 ep, int inCrSe);
int haeVapaaKoodi(int badge);
INT32 e_maaliaika(emittp *em, kilptietue *kilp, INT os);
INT addbadge(INT32 badge, INT kno, INT d, int toinen, INT msgfl);
INT rembadge(INT kno, INT os, int toinen, INT d);
INT remjkbadge(INT kno, INT32 bdg);
INT tarkista(emittp *em, kilptietue *kilp, INT *tulkinta, int lukija, INT haku);
int vatulkinta(emittp *em, int *valiajat);
INT tark_badge(emittp *em, kilptietue *kilp, bool tallfl);
INT lue_leimat(INT r);
INT lue_radat(INT r);
INT lue_radat_xml(INT r);
INT tark_radat(void);
void tall_etulos(INT32 badge, INT32 t, INT32 tms, int r_no, int lahde);
void lueRatatiedotUudelleen(void);
void laskeEm_VA(int d, int osuus, bool sail);
void kirjEventXml(wchar_t *outfname, bool kirjSarjat, bool kirjRadat, bool kirjOsanottajat);
int lueEventXml(wchar_t *filename, bool lueSarjat, bool lueRadat, bool lueOsanottajat);
void hae_enslahto(void);
int maaraaOsuusluku(bool kysy);
INT lueemitfile(void);
extern int httphaku(wchar_t *host, int port, wchar_t *page, int secure, char *buf, int buflen, int *haettu);
INT naytatiedot(emittp *em, kilptietue *kilp, INT os, int loppuosa);
int HaeSeuraLista(bool maafl, wchar_t (*sra)[LSEURA+5], int *nsra, int maxnsra);
void laheta_em(emittp *em, int rajaus, INT kielto);
INT addem(emittp *em, INT kielto);
INT lueem(emittp *em, INT ep);
void emit_tallenna(kilptietue *kilp, INT os, char trk, char *selitys, INT cn);
void lueseuraava(INT *kilpno, INT *os, emittp *em);
void lueedellinen(INT *kilpno, INT *os, emittp *em);
void poista_emit(emittp *em);
int pros_emit(wchar_t *msg);
INT leimat(void);
void emitlista(tulostusparamtp *tulprm);
int tee_emva(emitvatp *emva, emittp *em);
void emit_rap(tulostusparamtp *tulprm, INT kilpno, INT os);
void tark_rap(tulostusparamtp *tulprm, INT kilpno, INT os);
void seur_mtr(void);
void tarkyhteenveto(char co);
char tarktulostettavat(void);
void tarkraportit(tulostusparamtp *tulprm, char trk);
void kirjvaliajat(wchar_t *flnm);
void emitvaliajat(INT *srj, char co, char cr, INT kaik);
void lueemitkoodit(void);
int haekoordix(wchar_t *tunnus);
void haerastit(int ecode, int *rst, int *nr);
ratatp *haerata(kilptietue *kilp, int osuus);
wchar_t *MaaNimi(wchar_t *maa);
wchar_t *IOFStatus(kilptietue *kilp, int osuus);
wchar_t *ISOtime(wchar_t *st, wchar_t *datestr, int time);
wchar_t *sekTulos(wchar_t *st, int t, int pyor);

INT maalirasti(char *tunnus, INT koodi);
void aikaruutu(int ino);
void tallkvaihto(INT ekno, INT eos, INT kno, INT os, INT kielto);
void lahkvaihto(INT ekno, INT eos, INT kno, INT os, INT kielto);
void vaihdakilp(INT ekno, INT eos, INT vainos);
INT tark_partio(tulostusparamtp *tulprm, kilptietue *kilp, INT partiorap, int vajaat);
INT etsiesarja(emittp *em);
INT32 haeennakko(emittp *em, kilptietue *kilp, INT osuus);
void lue_lainat(int poista, int varoita);
INT lainakortti(kilptietue *kilp, INT os);
int autofile(void);
int start_autova(void);
jrec *getvaix(INT srj, INT os, INT va);
void putvaix(INT srj, INT os, INT va);
void relvaix(INT srj, INT os, INT va);
void writexml(TextFl *vafile, int emitva, int kaikki);
void kaikkisijat(tulostusparamtp *tulprm, int srj);
//void kaikkisijat(int srj);
void addtapahtuma(kilptietue *kilp, int osuus, int piste);
int wcstomaksu(wchar_t *st);
void startaf(INT kysy);
int kirjXmlOoOsuus(TextFl *outfl, kilptietue &kilp, int os, int piste, int level);
void kirjXmlOoPerus(TextFl *outfl, kilptietue &kilp, int level);

wchar_t *aikatowstr_cols_n(wchar_t *as, INT32 tl, int t0, wchar_t sep, int len);
wchar_t *eroaikatowstr(wchar_t *as, int ero, int len);
INT32 wstrtoaika_vap(wchar_t *str, int t0);
char *aikatostr_cols_n(char *as, INT32 tl, int t0, char sep, int len);
char *eroaikatostr(char *as, int ero, int len);
INT32 strtoaika_vap(char *str, int t0);
void asetaSrjLahto(int srj, int aika, bool siirto);
void asetaEraLahto(int era, int aika);

void draw_hline(int row, int col, int len);
void draw_vline(int row, int col, int len);
void draw_grchar(int row, int col, int ch);
void draw_hline2(int row, int col, int len);
void draw_vline2(int row, int col, int len);
void draw_grchar2(int row, int col, int ch);

#ifdef DBGFILE
void closedbgfile(void);
#endif

void lueKorRajat(void);
void initgdiprinter(tulostusparamtp *tulprm);
void luelahdepisteet(void);
void nollaayhdlkm(int os);
int wrt_st_x_srv(int cn, int len, char *buf, int *nsent);
void opencom(int cn, int baud, char parity, int bits, int sbits);

void tarkcom(LPVOID lpCn);
void tiedonsiirto(LPVOID lpCn);
void taustaThr(LPVOID lpCn);
void lue_regnlyThread(LPVOID lpCn);
void pros_emitThread(LPVOID lpCn);
int writeerrorkysy(UCHAR *msg);
void writeerror_w(wchar_t *txt, int wait, bool vainok);
void stopTCP(void);

extern int ToimintaTila;
extern	bool DeveloperMode;
extern	wchar_t WorkingDir[200];
extern kilpparamtp kilpparam;
extern sarjatietue Sarjat[MAXSARJALUKU+MAXYHD];
extern   INT32 tl_ylaraja;
extern   INT tunn_srj;
extern   INT tunn_raja;
extern   char tyhjarivi[];

extern   CRITICAL_SECTION tall_CriticalSection;
extern 	 CRITICAL_SECTION print_CriticalSection;
extern	 CRITICAL_SECTION autotul_CriticalSection;
extern   CRITICAL_SECTION loki_CriticalSection;
extern   CRITICAL_SECTION inb_CriticalSection;
extern   CRITICAL_SECTION outb_CriticalSection;
extern   CRITICAL_SECTION kilpdat_CriticalSection;
extern   CRITICAL_SECTION ajat_CriticalSection;
extern   CRITICAL_SECTION rastiva_CriticalSection;
extern   CRITICAL_SECTION emit_CriticalSection;
extern   CRITICAL_SECTION tcp_CriticalSection[MAX_PORTTI];
extern   CRITICAL_SECTION tcpip_CriticalSection;
extern	HTHREAD hTarkcomThread, hTsThread[MAX_PORTTI];
extern	HTHREAD hLuepakThread[MAX_PORTTI];
extern	HTHREAD taustaThread, hLkmThread;
extern   HTHREAD hAikacomThread;
extern	HTHREAD hProsEmitThread;
extern   HANDLE hStdIn, hStdOut, hConIn, hConOut;
extern  bool poistaSulje;
extern	int inLopetus;
extern	envdatatp EnvData;
extern	wchar_t exeName[50];
extern  int katkaisuPyydetty;
extern	bool sulkemassa;
extern	bool suljesuoraan;
extern  bool kuuluttaja;
extern   bool naytavaroitukset;
extern   int testi, lkmThreadOn;
extern   int taustaon, taustasulj, inGDIdoc;
extern   wchar_t *autokomento;
extern   long tcpkaynnistys[MAX_PORTTI+1];
extern   INT16 xSize, ySize;
extern   int writeerrorOn;
extern   int nakviive;
extern   int maxemvalah;
extern   int pros_emit_on;
extern   int emitfiletest;
extern   int sisaanluenta;
extern   bool RastiVaTuloste;
extern	 int analmaxosuuskesto;
extern   HTHREAD hpros_emitThread;
extern   int lahdepistehaku;

extern   INT16 osd;

extern	 bool ProsEmitOn;
extern   wchar_t sulkusalasana[12];
extern   INT  max_lahportti, max_portti;
extern   int lahcomserver[];
extern   int keyclose[];                   /* K�ytt�j� sulkenut portin */
extern   char tyhjarivi[];
extern   int kaynnistysvaihe;
extern   int chkstk;
extern   unsigned kone;
extern   int lisaa_edelle;
extern   int laika;
extern   char dhigh[];
extern   char shigh[];
extern   char  sgl[];
extern   char  dbl[];
extern   char sgle[];
extern   char dble[];
extern   int ndhigh;
extern   int nshigh;
extern   int nchsgle;
extern   int nchdble;
extern	wchar_t  alkulayout[];
extern   char  dataf2name[];
extern   char  dataf3name[];
extern   char  datafbname[];
extern   char  namefname[];
extern   wchar_t  luetfnm[];
extern   char  sarjafname[];
extern	 wchar_t  sarjaxmlfname[200];
extern  wchar_t rataxmlfname[200];
extern	wchar_t leimafname[200];
extern	wchar_t ratafname[200];
extern   wchar_t  obfilename[];

extern   char *kilparr;
extern   int maxrec, njrec;
extern   datafile datf2;
extern   FILE *fdatf2;
extern   kilpindex nameindex;
extern   kilpindex *ostlsindex;
extern   int reindex;
extern   int keylen;
extern  localparamtp localparam;
extern	tulostusparamtp lsttulparam;
extern	tulostusparamtp filetulparam;
extern	tulostusparamtp tartulparam;
extern	tulostusparamtp lokitulparam;
extern	tulostusparamtp aftulparam;
extern	tulostusparamtp *emittulparam;
extern   wchar_t  kilpailu[83];
extern   int lahhajonta;
extern   int prblockbits;
extern   int  origverify;
extern   int lataus;
extern   int bootfl;
extern   int jjfl;
extern   int esta_tall;
extern   INT  server_on;
extern   char konetunn[3];
extern   wchar_t naapuri[MAX_PORTTI][3];
extern   int talltaul;
extern   int iono;
extern   int tarkfl;
extern   int tarfl;
extern   int lahtarfl;
extern   int listfl;
extern   int spoolfl;
extern   int autofl;
extern struct {
	wchar_t afname[202];
	int aflaji;
	int autokomentolaji;
	wchar_t autokomento[202];
	wchar_t jakelumaar[202];
	bool vainMuutt;
	int afvali;
	bool af_flag;
	wchar_t aflstnm[202];
	wchar_t sanafname[202];
	wchar_t sanafchars;
	wchar_t wtitlea[202];
	wchar_t wheadera[202];
	} autofileparam;
extern   int pscr;
extern   wchar_t *psinit;
extern   char msga[81];
extern   int  kynnys;
extern   int stopprt;
extern   wchar_t listfname[81];
extern   int  t0;
extern   long t0tics;
extern   TMAALI  enslahto;
extern   TMAALI  tmaali, maaliajat[];
extern   int  ylmyoh;
extern   int  nilmt,nilmtt;
extern   int  minkilpno;
extern   int  maxkilpno;
extern   int  maxosuusluku;
extern   int  sarjaluku;
extern   int  nsarjayhd, nsarjayhd_tul, sarjayhdva[MAXYHD];
extern   wchar_t yhdsarjat[MAXYHD][MAXSARJALUKU];
extern   int varkynnys[MAXSARJALUKU+MAXYHD][MAXOSUUSLUKU];
extern   int  lkm_srj, lkm_os;
extern   wchar_t *header;
// extern   int ok;
extern   int  ntulost[];
extern   int  nhylt[],nkeskt[];
extern   int  neilt[],nost[];
extern   int  navoint[MAXOSUUSLUKU+1];
extern   int  nekoodi[MAXSARJALUKU+MAXYHD][MAXOSUUSLUKU];
extern   int  sjfl[MAXSARJALUKU+MAXYHD];
extern   int  nilm[MAXSARJALUKU+MAXYHD+1];
extern   int  ntulos[MAXSARJALUKU+MAXYHD+1][MAXOSUUSLUKU][VAIKALUKU+2];
extern   int  tlsmuutos[MAXSARJALUKU+MAXYHD][MAXOSUUSLUKU][VAIKALUKU+2];
extern   int  ntulosix[MAXSARJALUKU+MAXYHD+1][MAXOSUUSLUKU][VAIKALUKU+2];
extern   int  njoukhyl[MAXSARJALUKU+MAXYHD+1];
extern   int  njoukkesk[MAXSARJALUKU+MAXYHD+1];
extern   int  nhyl[MAXSARJALUKU+MAXYHD+1][MAXOSUUSLUKU];
extern   int  nkesk[MAXSARJALUKU+MAXYHD+1][MAXOSUUSLUKU];
extern   int  neil[MAXSARJALUKU+MAXYHD+1][MAXOSUUSLUKU];
extern   int  navoin[MAXSARJALUKU+MAXYHD+1][MAXOSUUSLUKU];
extern   int  nylahto[MAXSARJALUKU+MAXYHD+1][MAXOSUUSLUKU];
//extern   jrec *jalku[MAXSARJALUKU+MAXYHD+1][MAXOSUUSLUKU][VAIKALUKU+2];
extern   INT jalku[MAXSARJALUKU+MAXYHD+1][MAXOSUUSLUKU][VAIKALUKU+6];
extern   __int64 *jarjtulos[MAXYHD+1][MAXOSUUSLUKU][VAIKALUKU+4];
extern   INT16 *jrjseur[MAXYHD+1];
extern   INT josalku[MAXSARJALUKU+MAXYHD+1][MAXOSUUSLUKU];
extern   __int64 *jarjostulos[MAXYHD+1][MAXOSUUSLUKU];
extern   INT16 *jrjosseur[MAXYHD+1];
extern   int  *kilpnoix;
extern   int  nimiixfl;
extern   tulostusparamtp autotulostusparam;
extern   tulosmuottp tulosmuot;
extern   tulosmuottp filetulosmuot;
extern   int  korjfl;
extern   int  eiltarra;
extern   int  initkehys;
extern   int  initform;
extern   int  enstls[MAXSARJALUKU+MAXYHD][MAXOSUUSLUKU];
extern   int  automaali[];
extern   int  fprior[MAXSARJALUKU+MAXYHD][MAXOSUUSLUKU];
extern   int  prior[MAXSARJALUKU+MAXYHD][MAXOSUUSLUKU];
extern   int  prior0[MAXSARJALUKU+MAXYHD];
extern   int  tauko;
extern   char laajuus;
extern   int  nparas;
extern   int  tofs;
extern   int  wincom;
extern   int  maxyhteys;
extern   int  portbase;
extern   int  portti[];
extern   int  maxnblock;
extern   char nprch;
extern   char trlate[];
extern   int  trlst, trtar, trloki;
extern   int  iobufr;
extern   int  iobufmaxnr;
extern   char copybuf[];
extern   int  kaksoistar;
extern   int  nktarra;
extern   int  wtarra;
extern   int  nrtarra;
extern   char tarstr[][13];
extern   tarrak  kentta[25];
extern   char form[], kehys1[];
extern   char savebox[], errbox[];
extern   int tulfl;
extern   int comfl, comopen[MAX_PORTTI], comclose[MAX_PORTTI];
extern   int tcomfl;
extern   int estavalitys[MAX_LAHPORTTI];
extern   int immed;
extern   INT  lahec[MAX_LAHPORTTI];
extern   INT  lahkello[MAX_LAHPORTTI];
extern   INT  lahkelloraja[MAX_LAHPORTTI];
extern   bool  lahkellovain[MAX_LAHPORTTI];
extern   UINT32 kirjheti;
extern   int katkkierto[MAX_LAHPORTTI];
extern   char ch_pty[];
extern   int baud[], nprtch, comkesto[];
extern   char pty[MAX_PORTTI];
extern   int combits[MAX_PORTTI];
extern   int stopbits[MAX_PORTTI];
extern   INT inbens, inbseur;
extern   long cjens[], cjseur[];
extern   int obfile, levypusk;
extern   FILE *fobfile;
extern   int lah_alku[MAX_LAHPORTTI];
extern   INT lah_vaihto[MAX_LAHPORTTI];
extern   int tarlahcom[MAX_LAHPORTTI];
extern   int lahcom[];
extern   int vastcom[];
extern   INT yhteys_on[MAX_LAHPORTTI];
extern   int lah_tiedostot[MAX_LAHPORTTI];
extern   bool lahkaikkitied;
extern   int dcom;
extern   int jonokynnys;
extern   int ennakoi;
extern	 int aikaero[NREGNLY+1];
extern   int estaneg, ylimraja, uusinaika, samapisteraja, muutoskysely;
extern   int  lukijalahde[NREGNLY];
extern   int maxjono, yhtjonot, akttm;
extern   int aika_jono[1][45], emitjono;
extern   int yhtaikajono[MAX_LAHPORTTI];
extern   aikajonotp *aikajono[MAXJONO];
extern   wchar_t aikaflname[200];
extern   aikatp viim_time;
extern   int muut_time;
extern   int od_fl;
extern   TMAALI od_aika;
extern	 lahdepistetp *lahdepisteet[MAXSARJALUKU+1][MAXOSUUSLUKU+1];
extern	 lahdepistetp *lahdejonot[MAXSARJALUKU+1][MAXOSUUSLUKU+1];
extern   int modif[MAXSARJALUKU+MAXYHD][MAXOSUUSLUKU];
extern   int timefl;
extern   int aani;
extern   int n_lisaa;
extern   int loki, lokiTCP, mloki;
extern   HANDLE hLoki;
extern   wchar_t lokifname[];
extern   int com_ajat[];
extern   long rukkausvali,rukkaa;
extern   int edista;
extern	 int odota;
extern   int aikaTCPstatus;
extern   int lah_kello[];
extern   int lah_kello_nyt[];
extern   long kellovali[];
extern   int kello_baud;
extern   int status_on, ajat_on;
extern   TMAALI tvalmis;
extern   int valiajat;
extern   int maxnvaika;
extern   int vainvaliajat;
extern   int vahandle;
extern   int com_valiajat[];
extern   int va_mpiste[MAXJONO];
extern   int ol_osuus, os_raja;
extern   wchar_t ch_piste[];
extern   INT aika_tunnus[1][45];
extern	 INT aika_tunnus_lkm;
extern   INT lahtoryhma;
extern   int aika_com, com_aika, aika_esto;
extern   char aika_int_mask;
extern   INT kello_baud, regnly_no[NREGNLY], kello_bits;
extern   int regnly[NREGNLY];
extern   int od_regnly;
extern   INT32 t0_regnly;
extern   int t0_regn[NREGNLY];
extern   int port_regnly[NREGNLY];
extern   int regnlyhetki[NREGNLY];
extern   int regnly_open[NREGNLY];
extern   INT cn_regnly[2 * NREGNLY];
extern   long maxero;
extern   int kerro_regnly;
extern   INT usb_regnly[NREGNLY];
extern   int kello_baud;
extern   int t0_autova;
extern   int int_autova;
extern   int addr_autova;
extern   int autova_open;
extern   INT  emitfl, nbadge[2], emittoisto, vaikavert, ilmtunt, vaajat;
extern   bdg_kno_tp *bdg_kno[2];
extern	int maxpaikat_t;
extern	int maxpaikat[MAXSARJALUKU];
extern   int taulu_com, taulu_baud;
extern   int jatktaulu, htaulu, udptaulu;
extern   int ratavalpit;
extern   int ampusakot;

extern   int maxaika[MAXSARJALUKU], sakkoaskel[MAXSARJALUKU], askelsakko[MAXSARJALUKU];
extern   int joustoviesti, joustopakotavaihto;
extern   bool esta_uusikaytto;

extern   INT  ajatfl, ilmlainat, emitkd, relax, emitsivu, emittoisto;
extern   INT  siritreuna;
extern	 bool siritloki;
extern	 bool siritsync;
extern	 int sirithead, sirittail;
extern	 wchar_t siritbuf[SIRITBUFLEN+1];
extern   INT jalkisyotto, ohitaleimat, ohitatoisto;
extern   INT emitanal_fl, maalirastipois;
extern   INT joukkueemit;
extern   INT salli_emit_ensin;
extern   ratatp *rata;
extern   INT  nrata, kaikki_ajat[NREGNLY+1], vaadiaika, vainpiste[NREGNLY+2];
extern   INT  nesitt, nesit[MAXSARJALUKU+MAXYHD];
extern   char maalitp[10];
extern   INT *emitjarr[MAXOSUUSLUKU];

extern   int bytecount, bytecountmax;
extern   INT com_emit[MAX_LAHPORTTI];
extern   int emitfile;
extern   FILE *femitfile;
extern	 INT valonaytto;
extern   INT com_emitva[MAX_LAHPORTTI];
extern   wchar_t emitfname[];
extern   UINT *emitpos;
extern   INT emitptr, emithead, emithead2;
extern   INT autorap, comautorap;
extern   char autorapsrj[MAXSARJALUKU+MAXYHD];
extern   INT ennakko, huomaatark;
extern   char viimtark;
extern   INT esitark;
extern	 int emitaglisa;
extern   wchar_t initfont_emrap[];
extern   INT bdg_muutt;
extern   INT autokilp;
extern   int seurkrivi;
extern   INT estaemittoisto;
extern	 int sallisummavirhe, lukutoisto;
extern   bool emitluenta;
extern	 int pollaa, TCPpoll[NREGNLY+1];
extern   int naytahajonta;
extern   wchar_t initfont_emva[];
extern   INT val_korkein;
extern	 bool emitvafl;
extern   bool emitvaloki;

extern   INT  comtype[MAX_PORTTI];
extern   ipparamtp ipparam[MAX_PORTTI+1];
extern   HANDLE hComm[MAX_PORTTI];
extern   INT  fileyht, tcpyhteys;
extern   int ajanottofl, sail_ajat;
extern   INT xmlsarja;
extern   bool XMLtietue;
extern   int datatallfl[2];

#ifdef DBGFILE
extern   int dbgtofile;
#endif

#if !defined(LUENTA)
extern   IOFCourseData CourseData;
#endif
extern rastikoordtp rastikoord[MAXNPISTE];
extern maptp Map;

extern int profiloi;
extern int scale, n_fld[3];
extern char merkit, av;
extern wchar_t paaots[];
extern wchar_t sarjaots[];
extern wchar_t alaots[];
extern char *fldname[];
extern   int TCPviive_lah[MAX_PORTTI];
extern   int TCPviive_nak[MAX_PORTTI];
extern   int TCPviive_pak[MAX_PORTTI];
extern	int lahhajonta;
extern	int pkarki[MAXSARJALUKU+MAXYHD][MAXOSUUSLUKU][VAIKALUKU+2];
extern	int tarktapahtumat;
extern	int vuorokaudet, kierrokset;
extern   int monitoriLkm;

extern	INT emittime;
extern eThakuParamtp eTParam;
extern int inhttpHaku;
extern HTHREAD httphakuThread;
extern bool inkirjSQLThread;

#ifndef _CONSOLE
//extern   OSVERSIONINFO osvi;
int bSrchInt(int val, int *arr, int n);
int laskeemitvaliajat(emittp *em, kilptietue *kilp, emitvaanaltp **eva, rastivaanaltp **rstva, int *valuku);
void laskevertajat(void);
extern rvalitp *rvalit;
extern int rvluku;
extern int analvertosuus;
extern int analvertmax;
extern int SeurLstPaivita;
extern int SeurGrPaivita;
extern int TlsLstPaivita;
extern INT16 errMsgBox;

extern int (*korRaja)[2];
extern wchar_t *vipLaji;
extern unsigned int korVari[6];
extern sqlparamtp sqlparam;
extern sqlparamtp sqlEparam;
#endif // !_CONSOLE

#endif