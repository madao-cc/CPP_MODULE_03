# ==== Compiler & Flags ====
CXX		:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

# ==== Project Name ====
NAME		:= ex02

# ==== Directories ====
SRCDIR		:= source
OBJDIR		:= obj
INCDIR		:= include

# ==== Source Files ====
SRCS		:= main.cpp	\
		ClapTrap.cpp	\
		ScavTrap.cpp	\
		FragTrap.cpp	\

OBJS		:= $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# ==== Colors ====
RESET		:= \033[0m
BOLD		:= \033[1m
GREEN		:= \033[32m
BLUE		:= \033[34m
YELLOW		:= \033[33m
RED		:= \033[31m

# ==== Rules ====

# Default rule
all: $(NAME)

# Link executable
$(NAME): $(OBJS)
	@echo -e "$(BOLD)$(BLUE)[Linking]$(RESET) $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo -e "$(BOLD)$(GREEN)[✓] Build successful!$(RESET)"

# Object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@echo -e "$(BOLD)$(YELLOW)[Compiling]$(RESET) $<"
	@$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Remove object files
clean:
	@echo -e "$(BOLD)$(RED)[Cleaning]$(RESET) object files..."
	@rm -rf $(OBJDIR)

# Remove everything
fclean: clean
	@echo -e "$(BOLD)$(RED)[Cleaning]$(RESET) executable..."
	@rm -f $(NAME)

# Recompile
re: fclean all

# Run program after compiling
run: all
	@echo -e "$(BOLD)$(GREEN)[Running]$(RESET) $(NAME)...\n"
	@./$(NAME)

# Prevent make from using built-in rules
.PHONY: all clean fclean re run