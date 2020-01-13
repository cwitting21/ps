# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwitting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 17:17:02 by cwitting          #+#    #+#              #
#    Updated: 2019/12/08 18:09:25 by cwitting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import re
import sys
import shutil

shutil.rmtree("./valgrind", ignore_errors=True)
os.mkdir("./valgrind")
count = int(sys.argv[1])
while count :
    os.system("ARG=\"$(ruby -e \"puts (" + sys.argv[2] + " .. " + sys.argv[3] + ").to_a.shuffle.join(\' \')\")\"; ./push_swap $ARG | valgrind ./checker $ARG 2> ./valgrind/test" + str(count) + ".txt")
    count -= 1
