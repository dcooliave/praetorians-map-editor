// ///////////////////////////////////////////// Hashing

#ifdef OC_STATICISSUES
inline unsigned long OCStringHashFunction(const char* c_data, int length)
{
#endif
  // Table of random values.  A good hash function will be as random
  // as possible to fill the table well, as well as be repeatable.  By
  // indexing into this table, we are doing a "derivative" of
  // Pearson's Hash function.
  
  // TODO: One one platform, Solaris, with -g, you may have troubles
  // linking ... this may need to be in a .o or as a global static.
  // Everybody else seems to be okay with this.
  static unsigned long StringHashArray[256] =
  {
    2998885266UL, 2906267139UL, 2831871165UL, 2180947562UL,
    342241519UL,  1483920592UL, 1932422408UL, 341603450UL,
    3444873416UL, 2727242209UL, 630072926UL,  641078858UL,
    869693583UL,  4170345219UL, 1817792895UL, 3140435515UL,
    3839435808UL, 4257928063UL, 3437810228UL, 456208845UL,
    654246144UL,  725123414UL,  3529625231UL, 3443739349UL,
    986468767UL,  2850099847UL, 2937843245UL, 15952070UL,
    2733254808UL, 3418696262UL, 1884832116UL, 2707638762UL,
    4061955054UL, 1524768324UL, 1857409239UL, 984599720UL,
    1663602767UL, 490998763UL,  2792412175UL, 1543968957UL,
    3918009426UL, 1758287264UL, 387551585UL,  912437380UL,
    2288452538UL, 1895335937UL, 3004163292UL, 3782896176UL,
    2416458418UL, 477734695UL,  1135636377UL, 3995422991UL,
    1749967120UL, 675537891UL,  4156583675UL, 3204280006UL,
    3385193876UL, 2836969729UL, 2521119727UL, 96173209UL,
    3039658279UL, 2623893641UL, 143946282UL,  1029668001UL,
    2618880542UL, 752095483UL,  453623663UL,  115030805UL,
    2213355383UL, 378843792UL,  1953454792UL, 1871951748UL,
    1997567001UL, 855915646UL,  3636863946UL, 3735975447UL,
    3603808789UL, 586517042UL,  3568986579UL, 801093841UL,
    319176168UL,  3531733140UL, 1806850893UL, 3742277840UL,
    1936695736UL, 2833668936UL, 3540196586UL, 491009931UL,
    4173035669UL, 2727434730UL, 2843314407UL, 637165587UL,
    1789170103UL, 3542627662UL, 4077098571UL, 3460280404UL,
    1786747844UL, 3773232327UL, 3974588455UL, 3989123667UL,
    3633047560UL, 1918958431UL, 2408907989UL, 118164847UL,
    81876412UL,   1128727833UL, 3351229754UL, 3900774305UL,
    2205705537UL, 2759298100UL, 420219909UL,  3929034430UL,
    225014628UL,  255759976UL,  4181693680UL, 1763850673UL,
    538975386UL,  726264360UL,  3279891452UL, 861614531UL,
    98551874UL,   2994121695UL, 2814966966UL, 1021088725UL,
    563502056UL,  4248658741UL, 4084672886UL, 2948848034UL,
    983176829UL,  3055642698UL, 4231535260UL, 926653184UL,
    2609877921UL, 3123230967UL, 1468626387UL, 1184069405UL,
    2723477212UL, 134297105UL,  1566752080UL, 326362563UL,
    3715055326UL, 3474475175UL, 1029478162UL, 63107222UL,
    2249638084UL, 3012161345UL, 708951073UL,  1835979858UL,
    2359282515UL, 3010212641UL, 3499528144UL, 3086191119UL,
    127693372UL,  1167852931UL, 4047789820UL, 3037739135UL,
    615809369UL,  1238402270UL, 305481548UL,  1606520108UL,
    3167786988UL, 895068705UL,  3276654193UL, 506854844UL,
    3822414820UL, 261053945UL,  1993404773UL, 2769350958UL,
    3066836248UL, 1284896264UL, 3772535725UL, 2951860508UL,
    3388293259UL, 3837598252UL, 977827481UL,  3973317369UL,
    1793174441UL, 2858291648UL, 2681933953UL, 3044854098UL,
    1901152134UL, 1472100563UL, 391633927UL,  63704335UL,
    338797603UL,  438066548UL,  144512857UL,  4083486384UL,
    649806762UL,  2124989672UL, 2979572589UL, 482606993UL,
    1145697711UL, 2580912367UL, 3364027204UL, 594903848UL,
    3358415470UL, 2298215684UL, 2691455785UL, 4073003076UL,
    4182674961UL, 167775131UL,  3100258289UL, 3654773325UL,
    2418539497UL, 3560373091UL, 693155387UL,  29723272UL,
    2955696562UL, 561294468UL,  1476817327UL, 367923538UL,
    341428945UL,  1841667551UL, 1478378560UL, 3897632610UL,
    156642199UL,  1610238546UL, 885337452UL,  1634498313UL,
    1578206332UL, 2361978355UL, 1135653240UL, 2762737010UL,
    3062605158UL, 1508553554UL, 3889883318UL, 2421732UL,
    2734287074UL, 2922989753UL, 3984144064UL, 2146380029UL,
    2284461927UL, 1467080045UL, 1557834172UL, 3541230070UL,
    3298796184UL, 2648868588UL, 1249575319UL, 2577345507UL,
    277319808UL,  1642532398UL, 3342294860UL, 2971550962UL,
    1564552917UL, 3602523365UL, 2754714652UL, 641525160UL,
    1943500343UL, 2042626751UL, 3264170197UL, 404320809UL,
    3228091759UL, 3306121888UL, 2682344718UL, 324014959UL
  };
  
#ifndef OC_STATICISSUES
  inline unsigned long OCStringHashFunction(const char* c_data, int length)
  {
#endif
  
    // Compute a derivate of Pearson's hash function
    unsigned long value = 0;
    for (int ii=0; ii<length; ii++)
    {
      value ^= StringHashArray[(unsigned char)c_data[ii]^(ii + length)];
    }
    return value;
  }
  
  
  
  
  