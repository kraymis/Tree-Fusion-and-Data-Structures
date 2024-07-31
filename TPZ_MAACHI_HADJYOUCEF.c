  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

#include <stdio.h>
#include <stdlib.h>
#include <Time.h>


  typedef int bool ;

  #define True 1
  #define False 0
  #define COUNT 10


  /** Implémentation **\: ARBRE BINAIRE DE ENTIERS**/

  /** Arbres de recherche binaire **/

  typedef int Typeelem_Ai   ;
  typedef struct Noeud_Ai * Pointeur_Ai ;

  struct Noeud_Ai
    {
      Typeelem_Ai  Val ;
      Pointeur_Ai Fg ;
      Pointeur_Ai Fd ;
      Pointeur_Ai Pere ;
     } ;

  Typeelem_Ai Info_Ai( Pointeur_Ai P )
    { return P->Val;   }

  Pointeur_Ai Fg_Ai( Pointeur_Ai P)
    { return P->Fg ; }

  Pointeur_Ai Fd_Ai( Pointeur_Ai P)
    { return P->Fd ; }

  Pointeur_Ai Pere_Ai( Pointeur_Ai P)
    { return P->Pere ; }

  void Aff_info_Ai ( Pointeur_Ai P, Typeelem_Ai Val)
    {
       P->Val = Val ;
    }

  void Aff_fg_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fg =  Q;  }

  void Aff_fd_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fd =  Q ; }

  void Aff_pere_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Pere =  Q ; }

  void Creernoeud_Ai( Pointeur_Ai *P)
    {
      *P = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai))   ;
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_Ai( Pointeur_Ai P)
    { free( P ) ; }

   
  /** Variables du programme principal **/
  Pointeur_Ai A1=NULL;
  Pointeur_Ai A2=NULL;
  Pointeur_Ai A3i=NULL;
  Pointeur_Ai A3ii=NULL;
  Pointeur_Ai A3iii=NULL;
  Pointeur_Ai A3iv=NULL;
  Pointeur_Ai A3v=NULL;
  int J;
  int N;


  int Aleanombre( int N )
    { return ( rand() % N ); }
  int Min (int a, int b)
    {
      if (a < b) return(a);
      else return(b);
    }


  /** Prototypes des fonctions **/

  void Generate_arbre (Pointeur_Ai *Root);
  Pointeur_Ai Inordre_preordre (Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) ;
  Pointeur_Ai Inordre_postordre (Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) ;
  Pointeur_Ai Preordre_preordre (Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) ;
  Pointeur_Ai Postordre_postordre (Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) ;
  Pointeur_Ai Preordre_postordre (Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) ;
  void Insertion_arbre (Pointeur_Ai *Root , int *Value);
  Pointeur_Ai Findparent (Pointeur_Ai *Root , Pointeur_Ai *Current) ;
  Pointeur_Ai Findnextnodeinorder (Pointeur_Ai *Root , Pointeur_Ai *Current) ;
  void Dfs (Pointeur_Ai *Root);
  void Dfs_preorder (Pointeur_Ai *Root);
  void Dfs_postorder (Pointeur_Ai *Root);
  bool  Recherche (int *V , Pointeur_Ai *R) ;
  int  Nbr_noeud (Pointeur_Ai *P) ;
  Pointeur_Ai Premier_inordre (Pointeur_Ai *Racine) ;
  Pointeur_Ai Premier_postordre (Pointeur_Ai *Racine) ;
  Pointeur_Ai Suivant_preordre (Pointeur_Ai *Roots , Pointeur_Ai *Ps) ;
  Pointeur_Ai Suivant_postordre (Pointeur_Ai *Roots , Pointeur_Ai *Ps) ;
  bool  Verification (Pointeur_Ai *Ap1 , Pointeur_Ai *A3) ;
  bool  Verification_inv (Pointeur_Ai *A3 , Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) ;
  void Verification_all (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3);

  /**********  GENERATE ARBRES ********/
  /*************************************/
  /*************************************/
  /*************************************/


  void Generate_arbre (Pointeur_Ai *Root)
    {

        // Fonction qui permet de generer un arbre de recherche binaire


      /** Variables locales **/
      int I;

      /** Corps du module **/
     for( I  =  1 ;I <=  10000 ; ++I){
       N  =  Aleanombre(100000 ) ;
       while( Recherche ( & N , & *Root )) {
         N  =  Aleanombre(100000) ;
        
       } ;
       if( ( *Root == NULL )) {
         Creernoeud_Ai (& *Root ) ;
         Aff_info_Ai ( *Root , N ) ;
         }
       else
         {
         Insertion_arbre ( & *Root , & N ) ;
        
       } ;
      
     } ;
    
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /**********   INORDRE PREORDRE ********/
  /*************************************/
  /*************************************/
  /*************************************/
  Pointeur_Ai Inordre_preordre (Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) 
    {
    //FONCTION QUI PERMET DE FUSIONER DEUX ARBRES A1 ET A2 EN UN ARBRE A3 en utilisant parcours inordre pour A1 et preordre pour A2

      /** Variables locales **/
      Pointeur_Ai Inordre_preordre2 =NULL;
      Pointeur_Ai A1=NULL;
      Pointeur_Ai A2=NULL;
      Pointeur_Ai A3=NULL;
      int Valins;
      int _Px1;
      int _Px2;

      /** Corps du module **/
     A3  =  NULL ;
     A1  =  *Ap1 ;
     A2  =  *Ap2 ;
     A1  =  Premier_inordre ( & A1 ) ;
    /* A2:=Premier_postordre(A2); */
     while( ( A1 != NULL ) && ( A2 != NULL )) {
       Valins  =  Min ( Info_Ai ( A1 ) , Info_Ai ( A2 ) ) ;
       if( A3 == NULL) {
         Creernoeud_Ai (& A3 ) ;
         Aff_info_Ai ( A3 , Valins ) ;
         }
       else
         {
         Insertion_arbre ( & A3 , & Valins ) ;
        
       } ;
       if( Info_Ai ( A1 ) < Info_Ai ( A2 )) {
         A1  =  Findnextnodeinorder ( & *Ap1 , & A1 ) ;
         }
       else
         {
         A2  =  Suivant_preordre ( & *Ap2 , & A2 ) ;
        
       } ;
       if( ( A1 != NULL )) {
        ;
       } ;
       if( A2 != NULL) {
        ;
       } ;
      
     } ;
     if( A1 == NULL) {
       while( A2 != NULL) {
         _Px1 =  Info_Ai ( A2 ) ;
         Insertion_arbre ( & A3 , &_Px1) ;
         A2  =  Suivant_preordre ( & *Ap2 , & A2 ) ;
        
       } ;
      
     } ;
     if( A2 == NULL) {
       while( A1 != NULL) {
         _Px2 =  Info_Ai ( A1 ) ;
         Insertion_arbre ( & A3 , &_Px2) ;
         A1  =  Findnextnodeinorder ( & *Ap1 , & A1 ) ;
        
       } ;
      
     } ;
     Inordre_preordre2  =  A3 ;
    
     return Inordre_preordre2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /**********   INORDRE POSTORDRE ********/
  /*************************************/
  /*************************************/
  /*************************************/
  Pointeur_Ai Inordre_postordre (Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) 
    {
            //FONCTION QUI PERMET DE FUSIONER DEUX ARBRES A1 ET A2 EN UN ARBRE A3 en utilisant parcours inordre pour A1 et postordre pour A2

      /** Variables locales **/
      Pointeur_Ai Inordre_postordre2 =NULL;
      Pointeur_Ai A1=NULL;
      Pointeur_Ai A2=NULL;
      Pointeur_Ai A3=NULL;
      int Valins;
      int _Px1;
      int _Px2;

      /** Corps du module **/
     A3  =  NULL ;
     A1  =  *Ap1 ;
     A2  =  *Ap2 ;
     A1  =  Premier_inordre ( & A1 ) ;
     A2  =  Premier_postordre ( & A2 ) ;
     while( ( A1 != NULL ) && ( A2 != NULL )) {
       Valins  =  Min ( Info_Ai ( A1 ) , Info_Ai ( A2 ) ) ;
       if( A3 == NULL) {
         Creernoeud_Ai (& A3 ) ;
         Aff_info_Ai ( A3 , Valins ) ;
         }
       else
         {
         Insertion_arbre ( & A3 , & Valins ) ;
        
       } ;
       if( Info_Ai ( A1 ) < Info_Ai ( A2 )) {
         A1  =  Findnextnodeinorder ( & *Ap1 , & A1 ) ;
         }
       else
         {
         A2  =  Suivant_postordre ( & *Ap2 , & A2 ) ;
        
       } ;
       if( ( A1 != NULL )) {
        ;
       } ;
       if( A2 != NULL) {
        ;
       } ;
      
     } ;
     if( A1 == NULL) {
       while( A2 != NULL) {
         _Px1 =  Info_Ai ( A2 ) ;
         Insertion_arbre ( & A3 , &_Px1) ;
         A2  =  Suivant_postordre ( & *Ap2 , & A2 ) ;
        
       } ;
      
     } ;
     if( A2 == NULL) {
       while( A1 != NULL) {
         _Px2 =  Info_Ai ( A1 ) ;
         Insertion_arbre ( & A3 , &_Px2) ;
         A1  =  Findnextnodeinorder ( & *Ap1 , & A1 ) ;
        
       } ;
      
     } ;
     Inordre_postordre2  =  A3 ;
    
     return Inordre_postordre2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /**********   PREORDRE PREODRE ********/
  /*************************************/
  /*************************************/
  /*************************************/
  Pointeur_Ai Preordre_preordre (Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) 
    {
            //FONCTION QUI PERMET DE FUSIONER DEUX ARBRES A1 ET A2 EN UN ARBRE A3 en utilisant parcours preordre pour A1 et preordre pour A2

      /** Variables locales **/
      Pointeur_Ai Preordre_preordre2 =NULL;
      Pointeur_Ai A1=NULL;
      Pointeur_Ai A2=NULL;
      Pointeur_Ai A3=NULL;
      int Valins;
      int _Px1;
      int _Px2;

      /** Corps du module **/
     A3  =  NULL ;
     A1  =  *Ap1 ;
     A2  =  *Ap2 ;
     while( ( A1 != NULL ) && ( A2 != NULL )) {
       Valins  =  Min ( Info_Ai ( A1 ) , Info_Ai ( A2 ) ) ;
       if( A3 == NULL) {
         Creernoeud_Ai (& A3 ) ;
         Aff_info_Ai ( A3 , Valins ) ;
         }
       else
         {
         Insertion_arbre ( & A3 , & Valins ) ;
        
       } ;
       if( Info_Ai ( A1 ) < Info_Ai ( A2 )) {
         A1  =  Suivant_preordre ( & *Ap1 , & A1 ) ;
         }
       else
         {
         A2  =  Suivant_preordre ( & *Ap2 , & A2 ) ;
        
       } ;
       if( ( A1 != NULL )) {
        ;
       } ;
       if( A2 != NULL) {
        ;
       } ;
      
     } ;
     if( A1 == NULL) {
       while( A2 != NULL) {
         _Px1 =  Info_Ai ( A2 ) ;
         Insertion_arbre ( & A3 , &_Px1) ;
         A2  =  Suivant_preordre ( & *Ap2 , & A2 ) ;
        
       } ;
      
     } ;
     if( A2 == NULL) {
       while( A1 != NULL) {
         _Px2 =  Info_Ai ( A1 ) ;
         Insertion_arbre ( & A3 , &_Px2) ;
         A1  =  Suivant_preordre ( & *Ap1 , & A1 ) ;
        
       } ;
      
     } ;
     Preordre_preordre2  =  A3 ;
    
     return Preordre_preordre2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /**********   POSTORDRE POSTORDRE ********/
  /*************************************/
  /*************************************/
  /*************************************/
  Pointeur_Ai Postordre_postordre (Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) 
    {
            //FONCTION QUI PERMET DE FUSIONER DEUX ARBRES A1 ET A2 EN UN ARBRE A3 en utilisant parcours postordre pour A1 et postordre pour A2

      /** Variables locales **/
      Pointeur_Ai Postordre_postordre2 =NULL;
      Pointeur_Ai A1=NULL;
      Pointeur_Ai A2=NULL;
      Pointeur_Ai A3=NULL;
      int Valins;
      int _Px1;
      int _Px2;

      /** Corps du module **/
     A3  =  NULL ;
     A1  =  *Ap1 ;
     A2  =  *Ap2 ;
     A1  =  Premier_postordre ( & A1 ) ;
     A2  =  Premier_postordre ( & A2 ) ;
     while( ( A1 != NULL ) && ( A2 != NULL )) {
       Valins  =  Min ( Info_Ai ( A1 ) , Info_Ai ( A2 ) ) ;
       if( A3 == NULL) {
         Creernoeud_Ai (& A3 ) ;
         Aff_info_Ai ( A3 , Valins ) ;
         }
       else
         {
         Insertion_arbre ( & A3 , & Valins ) ;
        
       } ;
       if( Info_Ai ( A1 ) < Info_Ai ( A2 )) {
         A1  =  Suivant_postordre ( & *Ap1 , & A1 ) ;
         }
       else
         {
         A2  =  Suivant_postordre ( & *Ap2 , & A2 ) ;
        
       } ;
       if( ( A1 != NULL )) {
        ;
       } ;
       if( A2 != NULL) {
        ;
       } ;
      
     } ;
     if( A1 == NULL) {
       while( A2 != NULL) {
         _Px1 =  Info_Ai ( A2 ) ;
         Insertion_arbre ( & A3 , &_Px1) ;
         A2  =  Suivant_postordre ( & *Ap2 , & A2 ) ;
        
       } ;
      
     } ;
     if( A2 == NULL) {
       while( A1 != NULL) {
         _Px2 =  Info_Ai ( A1 ) ;
         Insertion_arbre ( & A3 , &_Px2) ;
         A1  =  Suivant_postordre ( & *Ap1 , & A1 ) ;
        
       } ;
      
     } ;
     Postordre_postordre2  =  A3 ;
    
     return Postordre_postordre2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /**********   PREORDRE POSTORDRE ********/
  /*************************************/
  /*************************************/
  /*************************************/
  Pointeur_Ai Preordre_postordre (Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) 
    {

     //FONCTION QUI PERMET DE FUSIONER DEUX ARBRES A1 ET A2 EN UN ARBRE A3 en utilisant parcours preordre pour A1 et postordre pour A2


      /** Variables locales **/
      Pointeur_Ai Preordre_postordre2 =NULL;
      Pointeur_Ai A1=NULL;
      Pointeur_Ai A2=NULL;
      Pointeur_Ai A3=NULL;
      int Valins;
      int _Px1;
      int _Px2;

      /** Corps du module **/
     A3  =  NULL ;
     A1  =  *Ap1 ;
     A2  =  *Ap2 ;
     A2  =  Premier_postordre ( & A2 ) ;
     while( ( A1 != NULL ) && ( A2 != NULL )) {
       Valins  =  Min ( Info_Ai ( A1 ) , Info_Ai ( A2 ) ) ;
       if( A3 == NULL) {
         Creernoeud_Ai (& A3 ) ;
         Aff_info_Ai ( A3 , Valins ) ;
         }
       else
         {
         Insertion_arbre ( & A3 , & Valins ) ;
        
       } ;
       if( Info_Ai ( A1 ) < Info_Ai ( A2 )) {
         A1  =  Suivant_preordre ( & *Ap1 , & A1 ) ;
         }
       else
         {
         A2  =  Suivant_postordre ( & *Ap2 , & A2 ) ;
        
       } ;
       if( ( A1 != NULL )) {
        ;
       } ;
       if( A2 != NULL) {
        ;
       } ;
      
     } ;
     if( A1 == NULL) {
       while( A2 != NULL) {
         _Px1 =  Info_Ai ( A2 ) ;
         Insertion_arbre ( & A3 , &_Px1) ;
         A2  =  Suivant_postordre ( & *Ap2 , & A2 ) ;
        
       } ;
      
     } ;
     if( A2 == NULL) {
       while( A1 != NULL) {
         _Px2 =  Info_Ai ( A1 ) ;
         Insertion_arbre ( & A3 , &_Px2) ;
         A1  =  Suivant_preordre ( & *Ap1 , & A1 ) ;
        
       } ;
      
     } ;
     Preordre_postordre2  =  A3 ;
    
     return Preordre_postordre2 ;
    }
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
  void Insertion_arbre (Pointeur_Ai *Root , int *Value)
    {

// FONCTION QUI PERMET DE FAIRE INSERTION D UNE VALEUR DANS UN ARBRE DE RECH BINAIRE ET ACCEPTE LES DOUBLONS

      /** Variables locales **/
      Pointeur_Ai Current=NULL;
      Pointeur_Ai Parent=NULL;
      Pointeur_Ai Valp=NULL;
      int Val;

      /** Corps du module **/
     Val  =  *Value ;
     if( ( *Root == NULL )) {
       Creernoeud_Ai (& *Root ) ;
       Aff_info_Ai ( *Root , *Value ) ;
      
     } ;
     Current  =  *Root ;
     Parent  =  NULL ;
     while( ( Current != NULL )) {
       Parent  =  Current ;
       if( *Value <= Info_Ai ( Current )) {
         Current  =  Fg_Ai ( Current ) ;
         }
       else
         {
         Current  =  Fd_Ai ( Current ) ;
        
       } ;
      
     } ;
     if( *Value <= Info_Ai ( Parent )) {
       Creernoeud_Ai (& Valp ) ;
       Aff_info_Ai ( Valp , *Value ) ;
       Aff_fg_Ai ( Parent , Valp ) ;
       }
     else
       {
       Creernoeud_Ai (& Valp ) ;
       Aff_info_Ai ( Valp , *Value ) ;
       Aff_fd_Ai ( Parent , Valp ) ;
      
     } ;
     Aff_pere_Ai(Valp,Parent);
     *Value  =  Val;
    }
  /**************************************/
  /**************************************/
  /**************************************/
  /**************************************/
  /*******FFINDDDD PAREEEENTT************/
  /*************************************/
  /*************************************/
  /*************************************/

// FONCTION POUR TROUVER LE PERE APARTIR DE RACINE ET LE NOEUD


  Pointeur_Ai Findparent (Pointeur_Ai *Root , Pointeur_Ai *Current) 
    {
      /** Variables locales **/
      Pointeur_Ai Findparent2 =NULL;
      Pointeur_Ai Findparenttemp=NULL;
      Pointeur_Ai Rootsave=NULL;
      Pointeur_Ai Currentsave=NULL;
      bool Trouv;

      /** Corps du module **/
     Rootsave  =  *Root ;
     Currentsave  =  *Current ;
     Trouv  =  True ;
     if( ( ( *Root == NULL ) && ( *Root == *Current ) )) {
       Findparenttemp  =  NULL ;
       Trouv  =  False ;
      
     } ;
     while( ( *Root != NULL )) {
       if( ( Fg_Ai ( *Root ) == *Current ) || ( Fd_Ai ( *Root ) == *Current )) {
         Findparenttemp  =  *Root ;
         Trouv  =  False ;
        
       } ;
       if( Info_Ai ( *Current ) < Info_Ai ( *Root )) {
         *Root  =  Fg_Ai ( *Root ) ;
         }
       else
         {
         *Root  =  Fd_Ai ( *Root ) ;
        
       } ;
      
     } ;
     if( Trouv == True) {
       Findparent2  =  NULL ;
       }
     else
       {
       Findparent2  =  Findparenttemp ;
      
     } ;
     *Root  =  Rootsave ;
     *Current  =  Currentsave ;
    
     return Findparent2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /**********  FIND NEXT INORDER ********/
  /*************************************/
  /*************************************/
  /*************************************/

// FONCTION POUR TROUVER LE SUIVANT INORDRE DANS UN ARBRE APARTIR DE RACINE DE LE NOEUD COURANT

  Pointeur_Ai Findnextnodeinorder (Pointeur_Ai *Root , Pointeur_Ai *Current) 
    {
      /** Variables locales **/
      Pointeur_Ai Findnextnodeinorder2 =NULL;
      Pointeur_Ai Successor=NULL;
      Pointeur_Ai Findtemp=NULL;
      Pointeur_Ai Roots=NULL;
      Pointeur_Ai Currents=NULL;
      bool Trouv;
      bool Trouv2;

      /** Corps du module **/
     Roots  =  *Root ;
     Successor  =  NULL ;
     Currents  =  *Current ;
     Trouv  =  False ;
     Trouv2  =  False ;
     if( Fd_Ai ( Currents ) != NULL) {
       Successor  =  Fd_Ai ( Currents ) ;
       while( Fg_Ai ( Successor ) != NULL) {
         Successor  =  Fg_Ai ( Successor ) ;
        
       } ;
       Findtemp  =  Successor ;
       Trouv2  =  True ;
      
     } ;
     while( ( ( Roots != NULL ) && ( Trouv == False ) )) {
       if( ( Info_Ai ( *Current ) < Info_Ai ( Roots ) )) {
         Successor  =  Roots ;
         Roots  =  Fg_Ai ( Roots ) ;
         }
       else
         {
         if( Info_Ai ( Currents ) > Info_Ai ( Roots )) {
           Roots  =  Fd_Ai ( Roots ) ;
           }
         else
           {
           Trouv  =  True ;
          
         } ;
        
       } ;
      
     } ;
     if( Trouv2 == True) {
       Findnextnodeinorder2  =  Findtemp ;
       }
     else
       {
       Findnextnodeinorder2  =  Successor ;
      
     } ;
    
     return Findnextnodeinorder2 ;
    }

  /*************************************/
  /*************************************/
  /*************************************/
  /*********  RECHERRRRRCHEEE ************/
  /*************************************/
  /*************************************/

//   FONCTION QUI VERFIE SI UNE VALEUR EXISTE DANS UN ARBRE OU PAS RETOURNE BOOLEEN

  bool  Recherche (int *V , Pointeur_Ai *R) 
    {
      /** Variables locales **/
      bool  Recherche2 ;
      int Vs;
      Pointeur_Ai Rs=NULL;
      bool Trouv;
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     Trouv  =  False ;
     Rs  =  *R ;
     Vs  =  *V ;
     if( *R == NULL) {
       Trouv  =  False ;
       }
     else
       {
       if( Vs == Info_Ai ( Rs )) {
         Trouv  =  True ;
         }
       else
         {
         if( Vs < Info_Ai ( Rs )) {
           _Px1 =  Fg_Ai ( Rs ) ;
           Trouv  =  Recherche ( & Vs , &_Px1) ;
           }
         else
           {
           _Px2 =  Fd_Ai ( Rs ) ;
           Trouv  =  Recherche ( & Vs , &_Px2) ;
          
         } ;
        
       } ;
      
     } ;
     Recherche2  =  Trouv ;
    
     return Recherche2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*********  NOMBRE DE NOEUDS ************/
  /*************************************/
  /*************************************/

// FONCTION POUR CALCULER NOMBRE DE NOEUDS

  int  Nbr_noeud (Pointeur_Ai *P) 
    {
      /** Variables locales **/
      int  Nbr_noeud2 ;
      int Val;
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( *P == NULL) {
       Val  =  0 ;
       }
     else
       {
       _Px1 =  Fd_Ai ( *P ) ;
       _Px2 =  Fg_Ai ( *P ) ;
       Val  =  1 + Nbr_noeud ( &_Px1) + Nbr_noeud ( &_Px2) ;
      
     } ;
     Nbr_noeud2  =  Val ;
    
     return Nbr_noeud2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*********  FIRST INORDRE ************/
  /*************************************/
  /*************************************/

// FONCTION POUR TROUVER LE PREMIER INORDRE DANS UN ARBRE APARTIR DE RACINE DE LE NOEUD COURANT


  Pointeur_Ai Premier_inordre (Pointeur_Ai *Racine) 
    {
      /** Variables locales **/
      Pointeur_Ai Premier_inordre2 =NULL;
      Pointeur_Ai Temp=NULL;
      Pointeur_Ai Racines=NULL;
      bool Trouve;
      Pointeur_Ai _Px1=NULL;

      /** Corps du module **/
     Racines  =  *Racine ;
     Trouve  =  False ;
     if( ( Racines == NULL ) && ( Trouve == False )) {
       Temp  =  NULL ;
       Trouve  =  True ;
      
     } ;
     if( ( Trouve == False )) {
       _Px1 =  Fg_Ai ( Racines ) ;
       Temp  =  Premier_inordre ( &_Px1) ;
       if( ( Temp != NULL )) {
         Trouve  =  True ;
        
       } ;
      
     } ;
     if( ( Trouve == False )) {
       Premier_inordre2  =  *Racine ;
       }
     else
       {
       Premier_inordre2  =  Temp ;
      
     } ;
    
     return Premier_inordre2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /**********  FIRST POSTORDRE ********/
  /*************************************/
  /*************************************/
  /*************************************/

// FONCTION POUR TROUVER LE PREMIER POSTORDRE DANS UN ARBRE APARTIR DE RACINE DE LE NOEUD COURANT


  Pointeur_Ai Premier_postordre (Pointeur_Ai *Racine) 
    {
      /** Variables locales **/
      Pointeur_Ai Premier_postordre2 =NULL;
      Pointeur_Ai Temp=NULL;
      Pointeur_Ai Racines=NULL;
      Pointeur_Ai _Px1=NULL;

      /** Corps du module **/
     Racines  =  *Racine ;
     Racines  =  Premier_inordre ( & Racines ) ;
     if( ( Fd_Ai ( Racines ) == NULL )) {
       Temp  =  Racines ;
       }
     else
       {
       _Px1 =  Fd_Ai ( Racines ) ;
       Temp  =  Premier_postordre ( &_Px1) ;
      
     } ;
     Premier_postordre2  =  Temp ;
    
     return Premier_postordre2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /**********  FIRST PREORDRE ********/
  /*************************************/
  /*************************************/
  /*************************************/

// FONCTION POUR TROUVER LE SUIVANT PREORDRE DANS UN ARBRE APARTIR DE RACINE DE LE NOEUD COURANT


  Pointeur_Ai Suivant_preordre (Pointeur_Ai *Roots , Pointeur_Ai *Ps) 
    {
      /** Variables locales **/
      Pointeur_Ai Suivant_preordre2 =NULL;
      Pointeur_Ai Root=NULL;
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      Pointeur_Ai Temp=NULL;
      bool Continue;

      /** Corps du module **/
     Root  =  *Roots ;
     P  =  *Ps ;
     if( Fg_Ai ( P ) != NULL) {
       Temp  =  Fg_Ai ( P ) ;
       }
     else
       {
       if( Fd_Ai ( P ) != NULL) {
         Temp  =  Fd_Ai ( P ) ;
         }
       else
         {
         Q  =  Findparent ( & Root , & P ) ;
         Continue  =  True ;
         while( ( Q != NULL ) && ( Continue )) {
           if( P == Fd_Ai ( Q )) {
             P  =  Q ;
             Q  =  Findparent ( & Root , & P ) ;
             }
           else
             {
             if( Fd_Ai ( Q ) != NULL) {
               Continue  =  False; }
             else
               {
               P  =  Q ;
               Q  =  Findparent ( & Root , & P ) ;
              
             } ;
            
           } ;
          
         } ;
         if( Q != NULL) {
           Temp  =  Fd_Ai ( Q ) ;
          
         } ;
        
       } ;
      
     } ;
     Suivant_preordre2  =  Temp ;
    
     return Suivant_preordre2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /******   SUIVANT POSTORDREE*************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/

// FONCTION POUR TROUVER LE SUIVANT POSTORDRE DANS UN ARBRE APARTIR DE RACINE DE LE NOEUD COURANT



  Pointeur_Ai Suivant_postordre (Pointeur_Ai *Roots , Pointeur_Ai *Ps) 
    {
      /** Variables locales **/
      Pointeur_Ai Suivant_postordre2 =NULL;
      Pointeur_Ai Root=NULL;
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      Pointeur_Ai Temp=NULL;
      bool Continue;

      /** Corps du module **/
     Root  =  *Roots ;
     P  =  *Ps ;
     Q  =  Findparent ( & Root , & P ) ;
     if( Q == NULL) {
       Temp  =  NULL ;
       }
     else
       {
       if( P == Fg_Ai ( Q )) {
         if( Fd_Ai ( Q ) != NULL) {
           P  =  Fd_Ai ( Q ) ;
           while( ( Fg_Ai ( P ) != NULL ) || ( Fd_Ai ( P ) != NULL )) {
             if( Fg_Ai ( P ) != NULL) {
               P  =  Fg_Ai ( P ); }
             else
               {
               if( Fd_Ai ( P ) != NULL) {
                 P  =  Fd_Ai ( P );
               } ;
              
             } ;
            
           } ;
           Temp  =  P ;
           }
         else
           {
           Temp  =  Q ;
          
         } ;
         }
       else
         {
         Temp  =  Q ;
        
       } ;
      
     } ;
     Suivant_postordre2  =  Temp ;
    
     return Suivant_postordre2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*******VVERIFICATION ARBRE 1 EN 3****/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/

  /* On verifie si tout les noeuds de A1/A2 existe dans A3*/

  bool  Verification (Pointeur_Ai *Ap1 , Pointeur_Ai *A3) 
    {
      /** Variables locales **/
      bool  Verification2 ;
      Pointeur_Ai A1=NULL;
      Pointeur_Ai Ap1s=NULL;
      Pointeur_Ai A1s=NULL;
      bool Temp;
      int _Px1;

      /** Corps du module **/
     Ap1s  =  *Ap1 ;
     A1s  =  Ap1s ;
     Temp  =  True ;
     while( ( A1s != NULL ) && ( Temp != False )) {
       _Px1 =  Info_Ai ( A1s ) ;
       if( Recherche ( &_Px1, & *A3 )) {
         Temp  =  True ;
         }
       else
         {
         Temp  =  False ;
        
       } ;
       A1s  =  Suivant_preordre ( & Ap1s , & A1s ) ;
      
     } ;
     Verification2  =  Temp ;
    
     return Verification2 ;
    }
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/
  /**********AA3 EN A1 ou A2************/
  /*************************************/
  /*************************************/
  /*************************************/
  /*************************************/

  /* On verifie si tout les noeuds de A3 existe dans A1 ou A2*/


  bool  Verification_inv (Pointeur_Ai *A3 , Pointeur_Ai *Ap1 , Pointeur_Ai *Ap2) 
    {
      /** Variables locales **/
      bool  Verification_inv2 ;
      Pointeur_Ai Ap3s=NULL;
      Pointeur_Ai A3s=NULL;
      Pointeur_Ai A1s=NULL;
      Pointeur_Ai A2s=NULL;
      bool Temp;
      int _Px1;
      int _Px2;

      /** Corps du module **/
     A1s  =  *Ap1 ;
     A2s  =  *Ap2 ;
     A3s  =  *A3 ;
     Ap3s  =  *A3 ;
     Temp  =  True ;
     while( ( A3s != NULL ) && ( Temp != False )) {
       _Px1 =  Info_Ai ( A3s ) ;
       _Px2 =  Info_Ai ( A3s ) ;
       if( ( Recherche ( &_Px1, & A2s ) ) || ( Recherche ( &_Px2, & A1s ) )) {
         Temp  =  True ;
         }
       else
         {
         Temp  =  False ;
        
       } ;
       A3s  =  Suivant_preordre ( & Ap3s , & A3s ) ;
      
     } ;
     Verification_inv2  =  Temp ;
    
     return Verification_inv2 ;
    }

    /* Une procedure pour verifier la double inclusion des (A1 et A2 dans A3) et (A3 dans A1 ou A2) */
/* et aussi si le nombre de noeuds dans A1+A2=A3 */


  void Verification_all (Pointeur_Ai *A1 , Pointeur_Ai *A2 , Pointeur_Ai *A3)
    {
      /** Variables locales **/
      Pointeur_Ai A1s=NULL;
      Pointeur_Ai A2s=NULL;
      Pointeur_Ai A3s=NULL;
      int Nb12;
      int Nb3;

      /** Corps du module **/
     A1s  =  *A1 ;
     A2s  =  *A2 ;
     A3s  =  *A3 ;
     Nb12  =  Nbr_noeud ( & *A1 ) + Nbr_noeud ( & *A2 ) ;
     Nb3  =  Nbr_noeud ( & *A3 ) ;
     if( ( ( Verification ( & *A1 , & *A3 ) == False ) || ( Verification ( & *A2 , & *A3 ) == False ) || ( Verification_inv ( & *A3 , & *A2 , & *A1 ) == False ) || ( Nb12 != Nb3 ) ) ) {
       printf ( " %s", "Erreur dans la fusion" ) ;
       }
     else
       {
       printf ( " %s", "\n Fusion avec succes\n" ) ;
      
     } ;
    
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// LES FONCTIONS AJOUTES DANS LE CADRE DE LA PARTIE C //////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// fonction pour calculer le nombre de feuilles 

int nbr_feuille(Pointeur_Ai P)
{
Pointeur_Ai root=P;
int cpt=0;
while (P != NULL)
{
    if ( (Fg_Ai(P) == NULL ) && (Fd_Ai(P) == NULL) )
    {
        cpt++;
    }
    P=Suivant_preordre(&root,&P);
}
return cpt;

}


// FONCTION QUI DONNE LE RAPPORT ENTRE NOMBRE DE FEUILLES ET NBR DE NOEUDS 

float Rapport_Nbf_par_Nbn(Pointeur_Ai A1)
{
float v= (float) nbr_feuille(A1) / Nbr_noeud(&A1);
return v;
}

// FONCTION RETOURNE MAX DE 5 ELTS
float maxOfFive(float a,float b, float c, float d, float e) {
    float max = a;

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    if (d > max) {
        max = d;
    }

    if (e > max) {
        max = e;
    }

    return max;
}

// FONCTION RETOURNE MAX DE 5 ELTS

float minOfFivefloat(float a, float b, float c, float d, float e) {
    float min = a;

    if (b < min) {
        min = b;
    }

    if (c < min) {
        min = c;
    }

    if (d < min) {
        min = d;
    }

    if (e < min) {
        min = e;
    }

    return min;
}

// FONCTION POUR MAX DE DEUX ELTS
int max2(int a, int b) 
{ // max de deux num
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// FONCTION POUR MIN DE DEUX ELTS
int min2(int a, int b) 
{ 
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

// FONCTION QUI CALCUL LA MAX HAUTEUR D UN ARBRE
int MaxHauteur(Pointeur_Ai root) {
    if (root == NULL) {
        return -1; 
    }

    int leftHeight = MaxHauteur(Fg_Ai(root));
    int rightHeight = MaxHauteur(Fd_Ai(root));

    return max2(leftHeight, rightHeight) + 1;
}

// UNE FONCTION QUI CALCULE LE NIVEAU DUN NOEUD DANS UN ARBRE

int calculateNodeLevelFromPointer(Pointeur_Ai root, Pointeur_Ai target) {
    if (root == NULL || target == NULL) {
        return -1; 
    }

    if (root == target) {
        return 0; 
    }

    int leftLevel = calculateNodeLevelFromPointer(Fg_Ai(root), target);
    if (leftLevel != -1) {
        return leftLevel + 1; 
    }

    int rightLevel = calculateNodeLevelFromPointer(Fd_Ai(root), target);
    if (rightLevel != -1) {
        return rightLevel + 1; 
    }

    return -1; 
}

// FONCTION QUI CALCUL LE NIVEAU MINIMALE DANS LA QUELLE EXISTE UNE FEUILLE


int Minlevel(Pointeur_Ai P)
{
 Pointeur_Ai R=P;
int minn=-1;
 while (R != NULL)
  {
    if ((Fg_Ai(R) == NULL ) && (Fd_Ai(R) == NULL ) )
    {
    if (minn==-1)
    {
    minn=calculateNodeLevelFromPointer(P,R);
    }
    else
    {
    int temp=calculateNodeLevelFromPointer(P,R);
    minn=min2(minn,temp);
    }
    }
    R=Suivant_preordre(&P,&R);
  }
  
return minn;
}


// FONCTION QUI CALCUL DIFFERENCE ENTRE DEUX NOMBRES
int diff(int a , int b){
return a-b;
}


// fonction calcul min de 5 elts entiers
int minOfFive(int a, int b, int c, int d, int e) {
    int min = a;

    if (b < min) {
        min = b;
    }

    if (c < min) {
        min = c;
    }

    if (d < min) {
        min = d;
    }

    if (e < min) {
        min = e;
    }

    return min;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// FONCTION QUI PERMET DE CALCULER LE DEGREE D'EQUILIBRE POUR LE CRITERE DE RAPPORT NB FEUILLES / NB NOEUDS
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void degree_rapport(Pointeur_Ai A1,Pointeur_Ai A2,Pointeur_Ai A3,Pointeur_Ai A4,Pointeur_Ai A5,int *degree_1,int *degree_2,int *degree_3,int *degree_4,int *degree_5)
{
  float minn=minOfFivefloat(Rapport_Nbf_par_Nbn(A1),Rapport_Nbf_par_Nbn(A2),Rapport_Nbf_par_Nbn(A3),Rapport_Nbf_par_Nbn(A4),Rapport_Nbf_par_Nbn(A5));


  if (minn==Rapport_Nbf_par_Nbn(A1))
  {
    (*degree_1)++;
  }
  if (minn==Rapport_Nbf_par_Nbn(A2))
  {
    (*degree_2)++;
  }

  if (minn==Rapport_Nbf_par_Nbn(A3))
  {
    (*degree_3)++;
  }
  if (minn==Rapport_Nbf_par_Nbn(A4))
  {
    (*degree_4)++;
  }
  if (minn==Rapport_Nbf_par_Nbn(A5))
  {
    (*degree_5)++;
  }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FONCTION QUI PERMET DE CALCULER LE DEGREE D'EQUILIBRE POUR LE CRITERE DE DIFFERENCE ENTRE MAX HAUTEUR ET HAUTEUR MIN
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void degree_hauteur(Pointeur_Ai a , Pointeur_Ai b , Pointeur_Ai c , Pointeur_Ai d , Pointeur_Ai e , int *c1 , int *c2 , int *c3 , int *c4 , int *c5 )
{

    int dif1=0 , dif2=0 , dif3=0 ,dif4=0 , dif5=0 ;
    int m ;
    dif1=diff(MaxHauteur(a),Minlevel(a));
     dif2=diff(MaxHauteur(b),Minlevel(b));
      dif3=diff(MaxHauteur(c),Minlevel(c));
       dif4=diff(MaxHauteur(d),Minlevel(d));
        dif5=diff(MaxHauteur(e),Minlevel(e));
    
    // printf("\n %d | %d | %d | %d| %d \n",dif1,dif2,dif3,dif4,dif5);

    
        m=minOfFive(dif1,dif2,dif3,dif4,dif5);
        if(m==dif1){
            (*c1)++ ;

        }
        if(m==dif2){
            (*c2)++ ;

        }
        if(m==dif3){
            (*c3)++ ;
        }
        if(m==dif4){
            (*c4)++ ;
        }
        if(m==dif5){
            (*c5)++ ;
        }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// FONCTION QUI PERMET DE CALCULER LE DEGREE D'EQUILIBRE POUR LE CRITERE DE temps d'execution
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void degree_time(Pointeur_Ai a , Pointeur_Ai b , Pointeur_Ai c , Pointeur_Ai d , Pointeur_Ai e ,int *c1,int *c2,int *c3,int *c4,int *c5, float time1 , float time2 , float time3 , float time4 , float time5 )
{

    float m ;
    
        m=minOfFivefloat(time1,time2,time3,time4,time5);

        if(m==time1){
            (*c1)++ ;

        }
        if(m==time2){
            (*c2)++ ;

        }
        if(m==time3){
            (*c3)++ ;
        }
        if(m==time4){
            (*c4)++ ;
        }
        if(m==time5){
            (*c5)++ ;
        }
}



double getElapsedTime(struct timespec start, struct timespec end) {
    double start_sec = (double)start.tv_sec + (double)start.tv_nsec * 1e-9;
    double end_sec = (double)end.tv_sec + (double)end.tv_nsec * 1e-9;
    return end_sec - start_sec;
}


  int main(int argc, char *argv[])
    {
     int degree_i=0,degree_ii=0,degree_iii=0,degree_iv=0,degree_v=0;
     clock_t start, end;
     double time_i,time_ii,time_iii,time_iv,time_v;

     /* Do the work. */
     srand(time(NULL));
     for( J  =  1 ;J <=  50; ++J){
       A1  =  NULL ;
       A2  =  NULL ;
       A3i  =  NULL ;
       A3ii  =  NULL ;
       A3iii  =  NULL ;
       A3iv  =  NULL ;
       A3v  =  NULL ;
      /* CREATION DES ARBRES */
       Generate_arbre ( & A1 ) ;

       Generate_arbre ( & A2 ) ;

      /*/////////////////////*/

      
      /* LE CAS "i" */  
     start = clock(); 
     A3i  =  Inordre_preordre ( & A1 , & A2 ) ;
     end = clock();

     time_i = ((float) (end - start)) / CLOCKS_PER_SEC;
   Verification_all ( & A1 , & A2 , & A3i ) ;
      /* FIN CAS "i" */
      
      /* LE CAS "ii" */
     start=clock();
       A3ii  =  Inordre_postordre ( & A1 , & A2 ) ;
     end = clock();
     time_ii = ((float) (end - start)) / CLOCKS_PER_SEC; 
    Verification_all ( & A1 , & A2 , & A3ii ) ;
      /* FIN CAS "ii" */

      /* LE CAS "iii" */
     start=clock();
       A3iii  =  Preordre_preordre ( & A1 , & A2 ) ;
    end = clock();
    time_iii = ((float) (end - start)) / CLOCKS_PER_SEC;

    Verification_all ( & A1 , & A2 , & A3i ) ;
      /* FIN CAS "iii" */

      /* LE CAS "iv" */
     start=clock();
     A3iv  =  Postordre_postordre ( & A1 , & A2 ) ;
     end = clock();
     time_iv = ((float) (end - start)) / CLOCKS_PER_SEC;
     Verification_all ( & A1 , & A2 , & A3iv ) ;
      /* FIN CAS "iv" */
     
      /* LE CAS "v" */
     start=clock();
       A3v  =  Preordre_postordre ( & A1 , & A2 ) ;
     end = clock();
     time_v = ((float) (end - start)) / CLOCKS_PER_SEC;
       Verification_all ( & A1 , & A2 , & A3v ) ;
      /* FIN CAS "v" */

//Calcul de degree d'equilibre :
degree_hauteur(A3i,A3ii,A3iii,A3iv,A3v,&degree_i,&degree_ii,&degree_iii,&degree_iv,&degree_v);
degree_rapport(A3i,A3ii,A3iii,A3iv,A3v,&degree_i,&degree_ii,&degree_iii,&degree_iv,&degree_v);
degree_time(A3i,A3ii,A3iii,A3iv,A3v,&degree_i,&degree_ii,&degree_iii,&degree_iv,&degree_v,time_i,time_ii,time_iii,time_iv,time_v);
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////

     } ;
printf("______________________________________________________________________________\n");
printf("\n -Le degree d'equilibre de chaque parcours pour 10000 noeuds : \n\n");
printf("Pour calculer le degre d'equilibre, nous avons utilise une approche qui \n\n");
printf ("resume les resultats des trois criteres en attribuant des points d'equilibre\n\n");
printf(" a chaque type de parcours qui satisfait le critere. Cela nous permet d'obtenir \n\n");
printf(" une mesure globale de l'equilibre pour chaque type de parcours. \n\n");
printf("*Plus le degree est elevEe, plus l'arbre est bien equilibre*\n\n");
printf("______________________________________________________________________________\n");
printf("Parcours INORDRE-PREORDRE : %d \nParcours INORDRE-POSTORDRE : %d \nParcours PREORDRE-PREORDRE : %d \nParcours POSTORDRE-POSTORDRE : %d \nParcours PREORDRE-POSTORDRE : %d\n",degree_i,degree_ii,degree_iii,degree_iv,degree_v);
printf("\n--- TP REALISE PAR : MAACHI MOHAMED ISLAM AYMEN G12 || HADJ YOUCEF MOHAMED ANIS G6----\n"); 
      system("PAUSE");
      return 0;
    }