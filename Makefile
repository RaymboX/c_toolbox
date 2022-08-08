
RM			= 	rm -rf
MAIN_GIT	= 	find . -maxdepth 1 -name '.git*'
SUB_GIT		=	find . -mindepth 2 -name '.git*'
RM_SUB_GIT	=	$(shell find . -mindepth 2 -name '.git*' -exec rm -rf {} +)
CACHE_FILES	=	/Users/mraymond/Library/Caches/*
TRASH_FILES	=	/Users/mraymond/.Trash/*
TRASH_DIR	=	/Users/mraymond/.Trash

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

list:
				@echo "---- main git (will not be delete) ----"
				@$(MAIN_GIT)
				@echo "\n---- sub git (will be delete) ----"
				@$(SUB_GIT)
				@echo "\n"

del:
				$(RM_SUB_GIT)
				@echo "remain sub git (empty = good)"
				@$(SUB_GIT)

gac:
				git add .
				git commit

mem_free:
				$(RM) $(CACHE_FILES)
				@echo "----if no file print after this, caches is empty----\n"
				ls -lia $(CACHE_DIR)
				$(RM) $(TRASH_FILES)
				@echo "----if no file print after this, trash is empty----\n"
				ls -lia $(TRASH_DIR)
