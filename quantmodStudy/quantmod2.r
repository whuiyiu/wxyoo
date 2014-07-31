####start work
require("zoo")
require("Defaults")
require("xts")
require("quantmod")

####download all data of Apple, Microsoft, Ocrala and Google
myenv<-new.env()
getSymbols(c("AAPL","MSFT","ORCL","GOOG"),env=myenv,scr="yahoo")
ls(envir=myenv)
####sum the volumes of Apple (from 2013.1 to 2013.10)
getSymbols("AAPL",env=myenv,scr="yahoo",from="2013-01-01",to="2013-10-31")
months=to.monthly(get("AAPL",envir=myenv))
months
sum(months[1:10,5])

####找出AAPL暴涨或暴跌的时间点
##找出AAPL开盘价或收盘价比前一天涨跌幅度超过2%的时间点
AAPL.Cl<-Delt(Cl(get("AAPL",envir=myenv)),type=("arithmetic"))
AAPL.Cl[which(abs(AAPL.Cl)>0.02),]
plot(AAPL.Cl)


