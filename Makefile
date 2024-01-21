NAME = abstract_data
OBJS_DIR = Obj
SRC_DIR = Src

# ===---===---===---===---===---===---===---===---===---===---===---===---

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INCLUDES = -I Includes

# ===---===---===---===---===---===---===---===---===---===---===---===---

all: vector_test

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	c++ $(CFLAGS) $(INCLUDES) -c $< -o $@

vector_test: $(OBJS_DIR)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/vector_test.cpp -o $(OBJS_DIR)/vector_test.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS_DIR)/vector_test.o
	./abstract_data

list_test: $(OBJS_DIR)
	c++ $(CFLAGS) $(INCLUDES) -c $(SRC_DIR)/list_test.cpp -o $(OBJS_DIR)/list_test.o
	c++ $(CFLAGS) -o $(NAME) $(OBJS_DIR)/list_test.o
	./abstract_data

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./abstract_data

doc:
	(cd Includes && doxygen .configDoxygen)
	open Includes/html/index.html

clean_doc:
	rm -rf Includes/html Includes/latex 

.PHONY: all clean fclean re run doc clean_doc vector_test
