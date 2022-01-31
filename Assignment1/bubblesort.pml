
/* CEATL book's bubsort */
/* Run instructions at the end */

#define Size 2
#define aMinIndx 1
#define aMaxIndx (Size-1)

/* Gonna "waste" a[0] because Sedgewick uses 1-based arrays */

active proctype bubsort()
{ byte j, t;   /* Init to 0 by SPIN     */
  bit a[Size]; /* Use 1-bit abstraction */
  
  /* Nondeterministic array initialization */
  
  do ::break ::a[1]=1 ::a[2]=1  od;

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

   do /* Subsequent ‘‘repeat’’ iterations */
   :: t!=a[1] ->
      t=a[aMinIndx]; j=aMinIndx+1;
      do
      :: (j > (aMaxIndx)) -> break /*-- For-loop exits --*/
      :: (j<=(aMaxIndx)) ->
        if
        :: (a[j-1] > a[j]) -> t=a[j-1]; a[j-1]=a[j]; a[j]=t
	:: (a[j-1] <= a[j])
        fi;
        j++ /*-- for-index increments --*/
      od  /*-- end of for-loop --*/
  :: t==a[1] -> break
  od;
   
  t=1; /*-- Comb from location-1 to look for sortedness --*/
  do
  :: t < aMaxIndx-1 -> t++
  :: t > aMinIndx   -> t--
  :: a[t] > a[t+1]  -> assert(0) /*- announce there is a bug! -*/
  od
}
   
