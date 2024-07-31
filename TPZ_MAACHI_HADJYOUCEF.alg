SOIT
A1,A2,A3i,A3ii,A3iii,A3iv,A3v des arb;
j,n un ENTIERS;

findparent UNE FONCTION (arb);
Premier_postordre une fonction(arb);
Premier_inordre une fonction(arb);
Suivant_preordre une fonction(arb);
Suivant_postordre une fonction(arb);
findnextnodeinorder une FONCTION(arb);
insertion_arbre une action;
generate_arbre une action;
recherche une fonction(booleen);
Nbr_Noeud une fonction(entier);
verification une fonction(booleen);
verification_inv une fonction(booleen);
verification_all une action;
/*********************************/
inordre_preordre une fonction(arb);
inordre_postordre une fonction(arb);
preordre_preordre une fonction(arb);
postordre_postordre une fonction(arb);
preordre_postordre une fonction(arb);





DEBUT
ECRIRE('--- TP REALISEE PAR : MAACHI MOHAMED ISLAM AYMEN G12 || HADJ YOUCEF MOHAMED ANIS G6 ---');

pour j:=1,10
A1:=nil;
A2:=nil;
A3i:=nil;
A3ii:=nil;
A3iii:=nil;
A3iv:=nil;
A3v:=nil;


/* CREATION DES ARBRES */
appel generate_arbre(A1);
appel generate_arbre(A2);
/*/////////////////////*/
/* LE CAS "i" */
A3i:=inordre_preordre(A1,A2);
Appel verification_all(A1,A2,A3i);
/* FIN CAS "i" */

/* LE CAS "ii" */
A3ii:=inordre_postordre(A1,A2);
Appel verification_all(A1,A2,A3ii);
/* FIN CAS "ii" */

/* LE CAS "iii" */
A3iii:=preordre_preordre(A1,A2);
Appel verification_all(A1,A2,A3iii);
/* FIN CAS "iii" */

/* LE CAS "iv" */
A3iv:=postordre_postordre(A1,A2);
Appel verification_all(A1,A2,A3iv);

/* FIN CAS "iv" */

/* LE CAS "v" */
A3v:=preordre_postordre(A1,A2);
Appel verification_all(A1,A2,A3v);

/* FIN CAS "v" */



fpour;

FIN



/********** GENERATE ARBRES ********/
/*************************************/
/*************************************/
/*************************************/

/* On utilise cette fonction pour generer les arbres */

ACTION generate_arbre(root)
SOIT
root un arb;
i un entier;
DEBUT
  POUR i:=1,50

  /* on verifie que la valeur a inserer n'existe pas dans l'arbre car c'est un recherche binaire pure */
  n:=ALEANOMBRE(1000);
  TQ recherche(n,root)
  n:=ALEANOMBRE(1000);
  FTQ;


  si (Root=NIL)
  CreerNoeud(Root);
  Aff_Info(Root,n);
  sinon
  Appel insertion_arbre(root,n);
  finsi;
  FPOUR;
FIN

/*************************************/
/*************************************/
/*************************************/

/**********  INORDRE PREORDRE ********/
/*************************************/
/*************************************/
/*************************************/

/* Fonction qui fais la fusion de A1 et A2 en parcours Inordre pour A1 et Preordre pour A2 */

Fonction inordre_preordre(AP1,Ap2):arb
SOIT
AP1,AP2,A1,A2,A3 des arb;
valins un entier;

DEBUT
A3:=NIL;
A1:=AP1;
A2:=AP2;

A1:=Premier_inordre(A1);


TQ (A1 # NIL) ET (A2 # NIL)
valins:=min(Info(A1),Info(A2));

SI A3 = NIL
CreerNoeud(A3);
Aff_info(A3,valins);
SINON
Appel insertion_arbre(A3,valins);
FINSI;


si Info(A1)<Info(A2)
A1:=findnextnodeinorder(AP1,A1);
SINON
A2:=suivant_preordre(AP2,A2);
FINSI;
si (A1 # NIL)
FINSI;
si A2 # NIL
FINSI;
FTQ;




si A1=NIL
 TQ A2 # NIL
  Appel insertion_arbre(A3,Info(A2));
A2:=Suivant_preordre(AP2,A2);
 FTQ;
FINSI;

si A2=NIL
 TQ A1 # NIL
  Appel insertion_arbre(A3,Info(A1));
  A1:=findnextnodeinorder(AP1,A1);
 FTQ;
FINSI;

inordre_preordre:=A3;
FIN
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/





/**********  INORDRE POSTORDRE ********/
/*************************************/
/*************************************/
/*************************************/
/* Fonction qui fais la fusion de A1 et A2 en parcours Inordre pour A1 et postordre pour A2 */

Fonction inordre_postordre(AP1,Ap2):arb
SOIT
AP1,AP2,A1,A2,A3 des arb;
valins un entier;

DEBUT
A3:=NIL;
A1:=AP1;
A2:=AP2;

A1:=Premier_inordre(A1);
A2:=Premier_postordre(A2);

TQ (A1 # NIL) ET (A2 # NIL)
valins:=min(Info(A1),Info(A2));

SI A3 = NIL
CreerNoeud(A3);
Aff_info(A3,valins);
SINON
Appel insertion_arbre(A3,valins);
FINSI;


si Info(A1)<Info(A2)
A1:=findnextnodeinorder(AP1,A1);
SINON
A2:=Suivant_postordre(AP2,A2);
FINSI;
si (A1 # NIL)
FINSI;
si A2 # NIL
FINSI;
FTQ;




si A1=NIL
 TQ A2 # NIL
  Appel insertion_arbre(A3,Info(A2));
A2:=Suivant_postordre(AP2,A2);
 FTQ;
FINSI;

si A2=NIL
 TQ A1 # NIL
  Appel insertion_arbre(A3,Info(A1));
  A1:=findnextnodeinorder(AP1,A1);
 FTQ;
FINSI;

inordre_postordre:=A3;
FIN
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/





/**********  PREORDRE PREODRE ********/
/*************************************/
/*************************************/
/*************************************/

/* Fonction qui fais la fusion de A1 et A2 en parcours Preordre pour A1 et Preordre pour A2 */

Fonction preordre_preordre(AP1,Ap2):arb
SOIT
AP1,AP2,A1,A2,A3 des arb;
valins un entier;

DEBUT
A3:=NIL;
A1:=AP1;
A2:=AP2;


TQ (A1 # NIL) ET (A2 # NIL)
valins:=min(Info(A1),Info(A2));

SI A3 = NIL
CreerNoeud(A3);
Aff_info(A3,valins);
SINON
Appel insertion_arbre(A3,valins);
FINSI;


si Info(A1)<Info(A2)
A1:=Suivant_preordre(AP1,A1);
SINON
A2:=Suivant_preordre(AP2,A2);
FINSI;
si (A1 # NIL)
FINSI;
si A2 # NIL
FINSI;
FTQ;




si A1=NIL
 TQ A2 # NIL
  Appel insertion_arbre(A3,Info(A2));
A2:=Suivant_preordre(AP2,A2);
 FTQ;
FINSI;

si A2=NIL
 TQ A1 # NIL
  Appel insertion_arbre(A3,Info(A1));
  A1:=Suivant_preordre(AP1,A1);
 FTQ;
FINSI;

preordre_preordre:=A3;
FIN
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/




/**********  POSTORDRE POSTORDRE ********/
/*************************************/
/*************************************/
/*************************************/

/* Fonction qui fais la fusion de A1 et A2 en parcours postordre pour A1 et Posrtordre pour A2 */

Fonction postordre_postordre(AP1,Ap2):arb
SOIT
AP1,AP2,A1,A2,A3 des arb;
valins un entier;

DEBUT
A3:=NIL;
A1:=AP1;
A2:=AP2;
A1:=Premier_postordre(A1);
A2:=Premier_postordre(A2);


TQ (A1 # NIL) ET (A2 # NIL)
valins:=min(Info(A1),Info(A2));

SI A3 = NIL
CreerNoeud(A3);
Aff_info(A3,valins);
SINON
Appel insertion_arbre(A3,valins);
FINSI;


si Info(A1)<Info(A2)
A1:=Suivant_postordre(AP1,A1);
SINON
A2:=Suivant_postordre(AP2,A2);
FINSI;
si (A1 # NIL)
FINSI;
si A2 # NIL
FINSI;
FTQ;




si A1=NIL
 TQ A2 # NIL
  Appel insertion_arbre(A3,Info(A2));
A2:=Suivant_postordre(AP2,A2);
 FTQ;
FINSI;

si A2=NIL
 TQ A1 # NIL
  Appel insertion_arbre(A3,Info(A1));
  A1:=Suivant_postordre(AP1,A1);
 FTQ;
FINSI;

postordre_postordre:=A3;
FIN
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/





/**********  PREORDRE POSTORDRE ********/
/*************************************/
/*************************************/
/*************************************/

/* Fonction qui fais la fusion de A1 et A2 en parcours preordre pour A1 et postordre pour A2 */

Fonction preordre_postordre(AP1,Ap2):arb
SOIT
AP1,AP2,A1,A2,A3 des arb;
valins un entier;

DEBUT
A3:=NIL;
A1:=AP1;
A2:=AP2;

A2:=Premier_postordre(A2);


TQ (A1 # NIL) ET (A2 # NIL)
valins:=min(Info(A1),Info(A2));

SI A3 = NIL
CreerNoeud(A3);
Aff_info(A3,valins);
SINON
Appel insertion_arbre(A3,valins);
FINSI;


si Info(A1)<Info(A2)
A1:=suivant_preordre(AP1,A1);
SINON
A2:=Suivant_postordre(AP2,A2);
FINSI;
si (A1 # NIL)
FINSI;
si A2 # NIL
FINSI;
FTQ;




si A1=NIL
 TQ A2 # NIL
  Appel insertion_arbre(A3,Info(A2));
A2:=Suivant_postordre(AP2,A2);
 FTQ;
FINSI;

si A2=NIL
 TQ A1 # NIL
  Appel insertion_arbre(A3,Info(A1));
  A1:=suivant_preordre(AP1,A1);
 FTQ;
FINSI;

preordre_postordre:=A3;
FIN
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/


/* INSEEERRTIOONNNN ARRRBREEEEEEEEEEE */
/**************************************/
/**************************************/
/**************************************/

/* Fonction pour inserer une valeur dans un arbre "elle accepte de inserer les doublons " */

ACTION insertion_arbre(root,value)
SOIENT
root,current,parent,valp un arb   ;
value,val un entier;
DEBUT
val:=value;

    SI (root=NIL)
    CREERNOEUD(root);
    Aff_Info(root,value);
    FINSI ;

    current := root;
    parent := NIL;


    TQ (current # NIL)
    parent:=current;
    SI value <= Info(current)
    current:=FG(current) ;
    SINON
    current:=FD(current);
    FINSI;
    FTQ;

    CreerNoeud(valp);
    SI value <=Info(parent)
    Aff_INFO(valp,value);
    Aff_FG(parent,valp);
    SINON
    Aff_INFO(valp,value);
    Aff_FD(parent,valp);
    FINSI  ;
    Aff_pere(valp,parent);
value:=val
FIN
/**************************************/
/**************************************/
/**************************************/
/**************************************/


/*******FINDDDD PAREEEENTT************/
/*************************************/
/*************************************/
/*************************************/

/*Fonction pour trouver le pere d'un noeud en donnant la racine et le pointeur du noeud */


FONCTION findparent(root, current): arb
SOIENT
root, current,findparenttemp,rootsave,currentsave DES ARB;
trouv un booleen;

DEBUT
rootsave:=root;
currentsave:=current;
trouv:=vrai ;

SI ((root = NIL) ET (root = current))
 findparenttemp:=NIL;
 trouv:=faux;
FSI;

TQ (root # NIL)
    SI (fg(root) = current) OU (fd(root) = current)
        findparentTEMP := root;
        trouv:=faux;
    FSI;

    SI Info(current) < Info(root)
        root := fg(root);
    SINON
        root := fd(root);

    FSI;
FTQ;
SI trouv=vrai
findparent := NIL;
SINON
findparent:=findparenttemp;
FINSI;
root:=rootsave   ;
current:=currentsave;
FIN
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/



/********** FIND NEXT INORDER ********/
/*************************************/
/*************************************/
/*************************************/

/*Fonction pour trouver le premier inordre dans un arbre de recherche binaire , "le fils le plus gauche" */


FONCTION findnextnodeinorder(root,current):arb
SOIT
root,current,successor,findtemp,roots,currents des arb;
trouv,trouv2 un booleen;
DEBUT
roots:=root;
successor:=NIL;
currents:=current;
trouv:=faux;
trouv2:=faux;

si fd(currents) # NIL

successor := fd(currents);
 TQ fg(successor) # NIL
  successor := fg(successor);
 FTQ;
findtemp:=successor;
trouv2:=vrai;

FINSI;

TQ ((roots # NIL) ET (trouv=faux))
 si (Info(current) < Info(roots))
    successor := roots;
    roots := fg(roots);
 sinon
  SI info(currents) > info(roots)
   roots:=fd(roots);
  sinon
  trouv:=vrai;
  FINSI;
 FINSI;
FTQ;

si trouv2=vrai
findnextnodeinorder:=findtemp;
sinon
findnextnodeinorder:=successor;
FINSI;
FIN
/*************************************/
/*************************************/
/*************************************/




/********* RECHERRRRRCHEEE ************/
/*************************************/
/*************************************/

/*Fonction qui recherche une valeur dans un arbre donnée et */
/* retourne un boolean vrai/faux si la valeur existe ou non dans l'arbre */


FONCTION recherche(v,r):booleen
SOIT
v,vs des entier;
r,rs des arb;
trouv:booleen;
DEBUT
trouv:=faux;
rs:=r;
vs:=v;

si r=nil
trouv:=faux;
sinon
 si vs = info(rs)
  trouv:=vrai;
  sinon
    si vs < info(rs)
      trouv:=recherche(vs,fg(rs));
    sinon
      trouv:=recherche(vs,fd(rs));
    finsi;
  finsi;
finsi;
recherche:=trouv;

FIN
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/



/********* NOMBRE DE NOEUDS ************/
/*************************************/
/*************************************/

/* Fonction qui donne le nombre de noeuds*/

FONCTION Nbr_Noeud(P):entier
SOIT
p UN ARB;
val un entier;
DEBUT
si p=nil
val:=0;
sinon
val:=1+Nbr_Noeud(fd(P))+Nbr_Noeud(fg(P));
finsi;
nbr_noeud:=val;
FIN
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/




/********* FIRST INORDRE ************/
/*************************************/
/*************************************/

/*Fonction qui donne le premier inordre dans un BST en donnant la racine */

   FONCTION Premier_inordre ( Racine ) : ARB
   SOIENT
       Racine UN ARB ;
       Temp UN ARB ;
       Racines UN ARB ;
       Trouve UN BOOLEEN ;

   DEBUT
       Racines := Racine ;
       Trouve := FAUX ;
       SI ( Racines = NIL ) ET ( Trouve = FAUX )
           Temp := NIL ;
           Trouve := VRAI ;

       FINSI ;
       SI ( Trouve = FAUX )
           Temp := Premier_inordre ( FG ( Racines ) ) ;
           SI ( Temp # NIL )
               Trouve := VRAI ;

           FINSI ;

       FINSI ;
       SI ( Trouve = FAUX )
           Premier_inordre := Racine ;

       SINON
           Premier_inordre := Temp ;

       FINSI ;

   FIN
/*************************************/
/*************************************/
/*************************************/



/********** FIRST POSTORDRE ********/
/*************************************/
/*************************************/
/*************************************/

/*Fonction qui donne le premier post-ordre dans un BST en donnant la racine */

FONCTION Premier_postordre ( Racine ) : ARB
   SOIENT
       Racine UN ARB ;
       Temp UN ARB ;
       Racines UN ARB ;

   DEBUT
       Racines := Racine ;
       racines:=premier_inordre(racines);
       SI ( FD ( Racines ) = NIL )
           Temp := racines ;

       SINON
           Temp := Premier_postordre ( FD ( Racines ) ) ;

       FINSI ;
       Premier_postordre := Temp ;

   FIN
/*************************************/
/*************************************/
/*************************************/



/********** SUIVANT PREORDRE ********/
/*************************************/
/*************************************/
/*************************************/

/* Une fonction qui donne le suivant preordre dans un noeud dans un arbre */

FONCTION Suivant_preordre ( roots,Ps):arb

   SOIENT

       root,roots,p,ps,q,temp UN ARB ;

       Continue DES BOOLEENS ;



   DEBUT
root:=roots;
p:=ps;


           SI FG ( P ) <> NIL

               temp:=fg(p);

           SINON

               SI FD ( P ) <> NIL

                   temp:=fd(p);

               SINON

                   Q := findparent(root,p);

                   Continue := VRAI ;

                   TQ ( Q <> NIL ) ET (Continue)

                       SI P = FD ( Q )

                           P := Q ;

                           Q := findparent(root,p);



                       SINON

                           SI FD ( Q ) <> NIL

                               Continue := FAUX

                           SINON

                               P := Q ;

                               Q := findparent(root,p) ;



                           Finsi;

                       Finsi;

                   FTQ ;

                   SI Q <> NIL

                       temp:=fd(q);

                   Finsi;

               Finsi;
           finsi;


Suivant_preordre:=temp;




   FIN
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/


/******  SUIVANT POSTORDREE*************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/

/* Une fonction qui donne le suivant postordre dans un noeud dans un arbre */

FONCTION Suivant_postordre ( roots ,ps ):arb

   SOIENT

       roots,root,ps,p,q,temp des arb;

      Continue un BOOLEEN ;



   DEBUT
root:=roots;
p:=ps;

           Q := findparent (root,P ) ;

           SI Q = NIL

               temp:=nil;

           SINON

               SI P = FG ( Q )

                   SI FD ( Q ) <> NIL

                       P := FD ( Q ) ;

                       TQ ( FG ( P ) <> NIL ) OU ( FD ( P ) <> NIL )


                           SI FG ( P ) <> NIL

                               P := FG ( P )

                           SINON

                               SI FD ( P ) <> NIL

                                   P := FD ( P )

                               Finsi;

                           Finsi;

                       FTQ ;

                       temp:=p;

                   SINON

                       temp:=q;

                   Finsi;

               SINON

                   temp:=q;

               Finsi;

           Finsi;



Suivant_postordre:=temp;
   FIN
/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/



/*******VERIFICATION ARBRE 1 EN 3****/
/*************************************/
/*************************************/
/*************************************/
/*************************************/

/* On verifie si tout les noeuds de A1/A2 existe dans A3*/

FONCTION verification(AP1,A3):booleen
SOIT
AP1,A1,A3,AP1S,A1S des arb;
temp un booleen;
DEBUT
AP1s:=AP1;
A1s:=AP1S;
temp:=vrai;

TQ (A1s # NIL) et (temp # faux)

si recherche(info(A1s),A3)
temp:=vrai;
sinon
temp:=faux;
finsi;
A1s:=suivant_preordre(AP1s,A1s);
FTQ;

verification:=temp;
FIN

/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/



/**********A3 EN A1 ou A2************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/

/* On verifie si tout les noeuds de A3 existe dans A1 ou A2*/

FONCTION verification_inv(A3,AP1,AP2):booleen
SOIT
AP1,AP2,A3,Ap3s,a3s,a1s,a2s des arb;
temp un booleen;
DEBUT

A1s:=AP1;
A2s:=AP2;
A3s:=A3;
Ap3s:=A3;
temp:=vrai;

TQ (A3s # NIL) et (temp # faux)

si (recherche(info(A3s),A2s)) ou (recherche (info(A3s),A1s))
temp:=vrai;
sinon
temp:=faux;
finsi;
A3s:=suivant_preordre(AP3s,A3s);

FTQ;

verification_inv:=temp;
FIN

/**********A3 EN A1 ou A2************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/

/* Une procedure pour verifier la double inclusion des (A1 et A2 dans A3) et (A3 dans A1 ou A2) */
/* et aussi si le nombre de noeuds dans A1+A2=A3 */


ACTION verification_all(A1,A2,A3)
SOIT
A1s,A2s,A3s,A1,A2,A3 des arb;
nb12,nb3 des entier;
DEBUT
A1s:=A1;
A2s:=A2;
A3s:=A3;
nb12:=Nbr_Noeud(A1) + Nbr_Noeud(A2);
nb3:=Nbr_Noeud(A3);
si ((verification(A1,A3)=faux) ou (verification(A2,A3)=faux) ou (verification_inv(A3,A2,A1)=faux) ou (nb12 # nb3)  )
ecrire('Erreur dans la fusion');
sinon
ecrire('Fusion avec succès');
finsi

FIN





/*************************************/
/*************************************/
/*************************************/
/*************************************/
/*************************************/








