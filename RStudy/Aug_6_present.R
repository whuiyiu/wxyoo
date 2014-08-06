library("ggplot2")
xyplot(mpg~disp,data=mtcars,groups=cyl,auto.key=list(corner=c(1,1)))
qplot(disp,mpg,data=mtcars,col=as.factor(cyl))
qplot(disp,mpg,data=mtcars,shape=as.factor(cyl))
qplot(disp,mpg,data=mtcars,size=as.factor(cyl))
dsmall <- diamonds[sample(nrow(diamonds),100),]
qplot(carat,price,data=diamonds)
qplot(log(carat),log(price),data=diamonds)
qplot(carat,x*y*z,data=diamonds)
qplot(carat,price,data=dsmall,colour=color)
qplot(carat,price,data=dsmall,shape=cut)
qplot(carat,price,data=diamonds,alpha=I(1/200))
qplot(carat,price,data=diamonds,geom=c("point","smooth"))
qplot(carat,price,data=dsmall,geom=c("point","smooth"),span=0.2)
qplot(carat,price,data=dsmall,geom=c("point","smooth"),span=0.5)
library(mgcv)
qplot(carat,price,data=dsmall,geom=c("point","smooth"),method="gam",formula=y ~ s(x))
qplot(carat,price,data=dsmall,geom=c("point","smooth"),method="gam",formula=y~s(x,bs="cs"))
qplot(color,price/carat,data=diamonds,geom="jitter",alpha=I(1/5))
qplot(color,price/carat,data=diamonds,geom="boxplot")
qplot(carat,data=diamonds,geom="histogram",binwidth=1,xlim=c(0,3))
qplot(carat,data=diamonds,geom="density",colour=color)
qplot(carat,data=diamonds,geom="histogram",fill=color)
qplot(color,data=diamonds,geom="bar",fill=color)
qplot(color,data=diamonds,geom="bar",fill=color,weight=carat)+
  scale_y_continuous("carat")

qplot(date,unemploy/pop,data=economics,geom="line")
qplot(date,uempmed,data=economics,geom="line")
year<-function(x) as.POSIXlt(x)$year + 1900
qplot(unemploy/pop,uempmed,data=economics,geom=c("point","path"))
qplot(unemploy/pop,uempmed,data=economics,geom="path",colour=year(date))
qplot(carat,data=diamonds,facets=color~.,geom="histogram",binwidth=0.1,xlim=c(0,3))
qplot(carat,..density..,data=diamonds,facets=color ~.,geom="histogram",binwidth=0.1,xlim=c(0,3))
qplot(carat,price,data=dsmall,colour=price,xlab="Price($)",ylab="weight(carats)",main="Price-weight relationship")
qplot(carat,price/carat,data=dsmall,colour=carat,ylab=expression(frac(price,carat)),xlab="Weight(carat)",main="Small diamonds",xlim=c(.2,1))
qplot(carat,price,data=dsmall,log="xy",geom=c("point","smooth"),colour=price)

qplot(displ,hwy,data=mpg,colour=factor(cyl))
qplot(displ,hwy,data=mpg,facets=.~year)+geom_smooth()

p<-qplot(displ,hwy,data=mpg,colour=factor(cyl))
summary(p)
####save the pic as r object
save(p,file=("plot1.rdata"))
####load the pic to r
load("plot.rdata")
####save the pic as png
ggsave("plot1.png",width=5,height=5)

p<-ggplot(diamonds,aes(carat,price,colour=cut))
p<-p+layer(geom="point")
p<-ggplot(diamonds,aes(x=carat))
p<-p+layer(geom="bar",geom_params=list(fill="steelblue"),
           stat="bin",
           stat_params=list(binwidth=2))
p

geom_histogram(binwidth=2,fill="steelblue")

ggplot(msleep,aes(sleep_rem/sleep_total,awake))+geom_point()
qplot(sleep_rem/sleep_total,awake,data=msleep)
qplot(sleep_rem/sleep_total,awake,data=msleep)+geom_smooth()
qplot(sleep_rem/sleep_total,awake,data=msleep,geom=c("smooth","point"))
ggplot(msleep,aes(sleep_rem/sleep_total,awake))+geom_point()+geom_smooth()

p<-ggplot(msleep,aes(sleep_rem/sleep_total,awake))
p<-p+geom_point()
p

library(scales)
bestfit<-geom_smooth(method="lm",se=F,colour=alpha("steelblue",0.5),size=2)
qplot(sleep_rem,sleep_total,data=msleep)+bestfit
qplot(awake,brainwt,data=msleep,log="y")+bestfit
qplot(bodywt,brainwt,data=msleep,log="xy")+bestfit

p<-ggplot(mtcars,aes(mpg,wt,colour=cyl))+geom_point()
p
mtcars<-transform(mtcars,mpg=mpg^2)
p%+%mtcars
