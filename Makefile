


#project repositories

R = c_toolbox

all: command

command:
		echo "clone R=<repositories name> : clone repositories from github"


clone:
		echo $(R)
		git clone git@github.com:RaymboX/$(R).git

mouse:
		defaults write -g com.apple.swipescrolldirection 0



