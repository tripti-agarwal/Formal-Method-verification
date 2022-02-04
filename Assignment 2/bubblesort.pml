
/* CEATL book's bubsort */
/* Run instructions at the end */

#define Size 10
#define aMinIndx 1
#define aMaxIndx (Size-1)

/* Gonna "waste" a[0] because Sedgewick uses 1-based arrays */

active proctype bubsort()
{ byte j, t;   /* Init to 0 by SPIN     */
  bit a[Size]; /* Use 1-bit abstraction */
  
  /* Nondeterministic array initialization */
  
  do ::break ::a[1]=1 ::a[2]=1 ::a[3]=1 ::a[4]=1 ::a[5]=1 ::a[6]=1 ::a[7]=1 ::a[8]=1 ::a[9]=1 od;

  t=a[aMinIndx]; j=aMinIndx+1;
  
   do /* First ‘‘repeat’’ iteration */
   :: (j >(aMaxIndx)) -> break /*-- For-loop exits --*/
   :: (j<=(aMaxIndx)) ->
   if
   :: (a[j-1] > a[j]) -> t=a[j-1]; a[j-1]=a[j]; a[j]=t
   :: (a[j-1] <= a[j])
   fi;
   j++
   od;
   byte k;
   k=aMaxIndx;
   do /* Subsequent ‘‘repeat’’ iterations */
   :: k!=1 ->
      t=a[aMinIndx]; j=aMinIndx+1;
      k--
      do
      :: (j > (k)) -> break /*-- For-loop exits --*/
      :: (j<=(k)) ->
        if
        :: (a[j-1] > a[j]) -> t=a[j-1]; a[j-1]=a[j]; a[j]=t
	:: (a[j-1] <= a[j])
        fi;
        j++ /*-- for-index increments --*/
      od  /*-- end of for-loop --*/
  :: k==1 -> break
  od;
   
  t=1; /*-- Comb from location-1 to look for sortedness --*/
  do
  :: t < aMaxIndx-1 -> t++
  :: t > aMinIndx   -> t--
  :: a[t] > a[t+1]  -> assert(0) /*- announce there is a bug! -*/
  od
}
   

