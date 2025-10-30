
from cmu_graphics import *
# Write your code here
#sound 
music = Sound ('https://github.com/AbdoulBa1/po/raw/refs/heads/main/Abdoul%20Ba.mp3')
music.play()
app.stepsPerSecond = 5
#sky/backround
Rect(1, 1, 400, 400, fill=gradient ('antiqueWhite','midnightblue', 'navy', 'black', start='center'))
#defining the background
def draw_rand_star():
  randx =randrange(0,400)
  randy =randrange(0,400)
  randsize=randrange(1,4)
  randpoint =randrange(3,6)
  return Star(randx, randy, randsize, randpoint, fill='cornsilk')
background_stars = Group()  
#loop to draw the stars
for i in range (100):
  background_stars.add(draw_rand_star())
  #function to fill the stars with colors
def onStep():
  for star in background_stars:
    randred = randrange(0,255)
    star.fill = rgb(randred,255,250)
  #stars 
star1 = Star(60, 210, 5, 4,fill='cornsilk')
star2 = Star(315, 130, 5, 4,fill='cornsilk')
star3 = Star(100, 170, 5, 4,fill='cornsilk')
star4 = Star(140, 180, 5, 4,fill='cornsilk')
star5 = Star(340, 210, 5, 4,fill='cornsilk')
star6 = Star(190, 190, 5, 4,fill='cornsilk')
star7 = Star(255, 255, 5, 4,fill='cornsilk')

#lines 
line1 = Line(60, 210, 100, 170, fill='floralwhite', lineWidth=1)
line2 = Line(100, 170, 140, 180, fill='floralwhite', lineWidth=1)
line3 = Line(140, 180, 190, 190, fill='floralwhite', 
lineWidth=1)
line4 = Line(190, 190, 255, 255, fill='floralwhite', lineWidth=1)
line5 = Line(255, 255, 340, 210, fill='floralwhite', lineWidth=1)
line6 = Line(340, 210, 315, 130, fill='floralwhite', lineWidth=1)
line7= Line(315, 130, 190, 190, fill='floralwhite', lineWidth=1)



app.run()
