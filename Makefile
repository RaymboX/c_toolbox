
RM			= 	rm -rf
DUSH		=	du -sh
MAIN_GIT	= 	find . -maxdepth 1 -name '.git*'
SUB_GIT		=	find . -mindepth 2 -name '.git*'
RM_SUB_GIT	=	$(shell find . -mindepth 2 -name '.git*' -exec rm -rf {} +)
CACHE_FILES	=	/Users/mraymond/Library/Caches/*
CACHE_DIR	=	/Users/mraymond/Library/Caches
TRASH_FILES	=	/Users/mraymond/.Trash/*
TRASH_DIR	=	/Users/mraymond/.Trash


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
				@echo "$Z____________CLEARING CACHE _____________"
				@echo "-----------CACHE SIZE $TBEFORE$Z------------"
				@$(DUSH) $(CACHE_DIR)
				@echo "----------------------------------------"
				@echo ""
				$(RM) $(CACHE_FILES)
				@echo ""
				@echo "-----------CACHE SIZE $GAFTER$Z-------------"
				@$(DUSH) $(CACHE_DIR)
				@echo "----------------------------------------"
				@echo "**if no file print after this, caches is empty**"
				@ls -a $(CACHE_DIR)
				@echo "\n"
				@echo "$C____________CLEARING TRASH _____________"
				@echo "----------TRASH SIZE $TBEFORE$C-------------"
				@$(DUSH) $(TRASH_DIR)
				@echo "----------------------------------------"
				@echo ""
				$(RM) $(TRASH_FILES)
				@echo ""
				@echo "-----------TRASH SIZE $GAFTER$C-------------"
				@$(DUSH) $(TRASH_DIR)
				@echo "**if no file print after this, trash is empty**"
				@ls -a $(TRASH_DIR)
				@echo "----------------------------------------$W"

ffc:			
				@make -i --no-print-directory ffc_strict
				@make -i --no-print-directory ffc_ptr 
#@make -i --no-print-directory ffc_large 

ffc_strict:
				@echo "----------strict search----------"
#				@find /usr/include -type f -name "*.h" -print | xargs grep ' '$(FCT)' (' || true
#				@find /usr/include -type f -name "*.h" -print | xargs grep "^extern .*"" $(FCT) "'(' || true
				@find /usr/include -type f -name "*.h" -print | xargs grep "^extern .* $(FCT) "'('|| true


ffc_ptr:
				@echo "----------ptr search----------"
#				@find /usr/include -type f -name "*.h" -print | xargs grep '*'$(FCT)' (' || true
#				@find /usr/include -type f -name "*.h" -print | xargs grep '*'$(FCT)' (' || true
#				@find /usr/include -type f -name "*.h" -print | xargs grep "^extern .*"'*'$(FCT)' (' || true
				@find /usr/include -type f -name "*.h" -print | xargs grep "^extern .*"'*'"$(FCT) "'(' || true

#ffc_large:
				@echo "----------large search----------"
				@find /usr/include -type f -name "*.h" -print | xargs grep "^extern .*"'*'"$(FCT) " || true
