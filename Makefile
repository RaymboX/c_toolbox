
RM			= 	rm -rf
DUSH		=	du -shc
MAIN_GIT	= 	find . -maxdepth 1 -name '.git*'
SUB_GIT		=	find . -mindepth 2 -name '.git*'
RM_SUB_GIT	=	$(shell find . -mindepth 2 -name '.git*' -exec rm -rf {} +)
USER_FILES	=	/users/mraymond/*
CACHE_FILES	=	/Users/mraymond/Library/Caches/*
CACHE_DIR	=	/Users/mraymond/Library/Caches
TRASH_FILES	=	/Users/mraymond/.Trash/*
TRASH_DIR	=	/Users/mraymond/.Trash
LINUX_H_PATH =  /usr/include
DARWIN_H_PATH =	/System/Volumes/Data/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include
UNAME_S     =	$(shell uname -s)
H_PATH		=	$(DARWIN_H_PATH)
ERROR_FILE	=	dush_err.txt
USER_SIZE	=	$(shell $(DUSH) $(USER_FILES) 2>$(ERROR_FILE) | grep total)
    

#SYSTEM VAR---------------------------------------------------------------------

T = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)

#project repositories

R = c_toolbox
FCT = write

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
				@clear
				@echo "\n      FIRST WE WAS AT: $(USER_SIZE)\n"
				@echo "$Z____________CLEARING CACHE _____________"
				@echo "-----------CACHE SIZE $TBEFORE$Z------------"
				@$(DUSH) $(CACHE_DIR)  | grep total
				@echo "----------------------------------------"
				@echo ""
				$(RM) $(CACHE_FILES)
				@echo ""
				@echo "-----------CACHE SIZE $GAFTER$Z-------------"
				@$(DUSH) $(CACHE_DIR) | grep total
				@echo "----------------------------------------"
				@echo "**if no file print after this, caches is empty**"
				@ls -a $(CACHE_DIR)
				@echo "\n"
				@echo "$C____________CLEARING TRASH _____________"
				@echo "----------TRASH SIZE $TBEFORE$C-------------"
				@$(DUSH) $(TRASH_DIR)  | grep total
				@echo "----------------------------------------"
				@echo ""
				$(RM) $(TRASH_FILES)
				@echo ""
				@echo "-----------TRASH SIZE $GAFTER$C-------------"
				@$(DUSH) $(TRASH_DIR)  | grep total
				@echo "**if no file print after this, trash is empty**"
				@ls -a $(TRASH_DIR)
				@echo "----------------------------------------$W\n"
				@echo "      NOW WE ARE AT: $(USER_SIZE)\n"
				@$(shell $(RM) $(ERROR_FILE))

ffc:			
ifeq ($(UNAME_S),Linux)
				H_PATH = $(LINUX_H_PATH)
endif				
				@make -i --no-print-directory ffc_strict
				@make -i --no-print-directory ffc_ptr 
				@make -i --no-print-directory ffc_large


ffc_strict:
				@echo "----------strict search----------"
#				@find /usr/include -type f -name "*.h" -print | xargs grep ' '$(FCT)' (' || true
#				@find /usr/include -type f -name "*.h" -print | xargs grep "^extern .*"" $(FCT) "'(' || true
#				@find $(H_PATH) -type f -name "*.h" -print | xargs grep "^extern .* $(FCT) "'('|| true
				@find $(H_PATH) -type f -name "*.h" -print | grep "^extern .* $(FCT) "'('|| true


ffc_ptr:
				@echo "----------ptr search----------"
#				@find /usr/include -type f -name "*.h" -print | xargs grep '*'$(FCT)' (' || true
#				@find /usr/include -type f -name "*.h" -print | xargs grep '*'$(FCT)' (' || true
#				@find /usr/include -type f -name "*.h" -print | xargs grep "^extern .*"'*'$(FCT)' (' || true
				@find $(H_PATH) -type f -name "*.h" -print | xargs grep $(FCT)

ffc_large:
				@echo "----------large search----------"
				@find $(H_PATH) -type f -name "*.h" -print | xargs grep "^extern .*"'*'"$(FCT) " || true

os:
				@echo $(UNAME_S)