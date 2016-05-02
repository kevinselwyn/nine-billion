#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int rc = 0, i = 0, l = 0, valid = 0;
	char *name = NULL;

	l = 9;
	name = malloc(sizeof(char) * (l + 1));

	if (!name) {
		printf("Memory error\n");

		rc = 1;
		goto cleanup;
	}

	strcpy(name, "AAABAAABA");

	while (strcmp(name, "FFFFFFFFF") != 0) {
		name[l - 1] += (char)1;

		for (i = l - 1; i >= 0; i -= 1) {
			if (name[i] == '[') {
				name[i] = 'A';
				name[i - 1] += (char)1;
			}
		}

		valid = 1;

		for (i = 0; i < l - 3; i++) {
			if (name[i] == name[i + 1] && name[i + 1] == name[i + 2] && name[i + 2] == name[i + 3]) {
				valid = 0;
			}
		}

		if (valid == 1) {
			printf("%s\n", name);
		}
	}

cleanup:
	if (name) {
		free(name);
	}

	return rc;
}