# description: 
from earsketch import*
init()
setTempo(120)
piano =  IRCA_BOMBA_YUBA_2_ELEC_PIANO
Y26 = Y26_ELECTRO_3

#for track 1
for i in range(1, 4,1):
  if(not(i == 2)):
        fitMedia (piano, 1, i, i+1)

# this is my songs 
fitMedia(piano , 3, 1,6 )
fitMedia(Y26_ELECTRO_3, 2,2,5)

# this my beats 
makeBeat(piano, 1, 1, "+00-00-00++0")# make beat for whoosh for track 1 starting measure one with provided beat.
makeBeat(Y26,1,2,"000-----0+00")# makes the beat for nature  for track one measure two with provided beat.
#makeBeat(,4,1,"+0+0+--0+0+--0+0+-" )# makes the beat for piano for track four with provided beat.
# this is my effects
setEffect(1, DELAY,DELAY_TIME,900)# DELAY create a repeated echo of track one.
setEffect(3, DELAY, DELAY_TIME,2)# makes track three louder. 

finish()

