
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

define REPO
commande gh repo list sur TourDebian

RaymboX/piscine_cpp                                                           private  17h
RaymboX/cub3d                                                                 public   Dec 13, 2022
RaymboX/opengl_raycast      from tuto on youtube                              private  Nov 16, 2022
RaymboX/minishell                                                             private  Nov  9, 2022
RaymboX/miniprojects        petits projets perso                              public   Nov  7, 2022
RaymboX/correction          projet corriger                                   private  Oct 26, 2022
RaymboX/c_toolbox           test etc                                          private  Oct 21, 2022
RaymboX/cpp                 Piscine cpp                                       private  Oct  4, 2022
RaymboX/philo                                                                 private  Sep  7, 2022
RaymboX/libft               c library for 42 projects                         private  Sep  7, 2022
RaymboX/so_long_tester      Tests de parcing de map pour so_long (projet 42)  public   Aug 11, 2022
RaymboX/pipex               42 project                                        private  Aug  9, 2022
RaymboX/piscine             project piscine 42                                private  Aug  3, 2022
RaymboX/push_swap           42 project                                        private  Aug  3, 2022
RaymboX/fdf                 42 project                                        private  Aug  3, 2022
RaymboX/get_next_line       42 project                                        private  Aug  3, 2022
RaymboX/printf              42 project                                        private  Aug  3, 2022
RaymboX/RaymGIT             All files                                         private  Aug  3, 2022
RaymboX/RaymboX_C_projects  Public repository to share                        public   Mar 21, 2022
RaymboX/RaymboX-VBA         Quelques projets en Excel VBA                     public   Feb 21, 2022
endef
export REPO

define ALIAS_LIST
alias cdd="cd ~/Documents" #RaymboX_alias_List----------
alias cd...="cd ../.." #RaymboX_alias_List----------
alias cd....="cd ../../.." #RaymboX_alias_List----------
endef
export ALIAS_LIST

all: command

command:
		echo "clone R=<repositories name> : clone repositories from github"

alias:
		echo "$$ALIAS_LIST" > alias_list
		@echo "$GFaite la commande: source ./alias_list pour appliquer$W"
#		cp ~/.bashrc cpy.bashrc
#		sed '/RaymboX_alias_List/d' cpy.bashrc > temp
#		mv temp cpy.bashrc
#		echo "$$ALIAS_LIST" >> cpy.bashrc
		
alais:
		make alias

repo:
		@echo "$$REPO"

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
				@make -i --no-print-directory ffc_strict
				@make -i --no-print-directory ffc_ptr 
				@make -i --no-print-directory ffc_large


ffc_strict:
				@echo "----------strict search----------"
#				@find /usr/include -type f -name "*.h" -print | xargs grep ' '$(FCT)' (' || true
#				@find /usr/include -type f -name "*.h" -print | xargs grep "^extern .*"" $(FCT) "'(' || true
#				@find $(H_PATH) -type f -name "*.h" -print | xargs grep "^extern .* $(FCT) "'('|| true
ifeq ($(UNAME_S),Linux)
				@find $(LINUX_H_PATH) -type f -name "*.h" -print | grep "^extern .* $(FCT) "'('|| true
endif

ffc_ptr:
				@echo "----------ptr search----------"
#				@find /usr/include -type f -name "*.h" -print | xargs grep '*'$(FCT)' (' || true
#				@find /usr/include -type f -name "*.h" -print | xargs grep '*'$(FCT)' (' || true
#				@find /usr/include -type f -name "*.h" -print | xargs grep "^extern .*"'*'$(FCT)' (' || true
				@find $(LINUX_H_PATH) -type f -name "*.h" -print | xargs grep $(FCT)

ffc_large:
				@echo "----------large search----------"
				@find $(LINUX_H_PATH) -type f -name "*.h" -print | xargs grep "^extern .*"'*'"$(FCT) " || true

os:
				@echo $(UNAME_S)
