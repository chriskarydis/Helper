#include "program.h" // Συμπερίληψη του αρχείου κεφαλίδας του προγράμματος

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Έλεγχος για τον σωστό αριθμό των ορισμάτων
    if (argc != 2) {
        fprintf(stderr, "Χρήση: %s όνομα_αρχείου\n", argv[0]);
        displayErrorMessage("Λανθασμένος αριθμός ορισμάτων.", ARGUMENT_ERROR);
        return ARGUMENT_ERROR;
    }

    // Δημιουργία ενός αγωγού για επικοινωνία μεταξύ διεργασιών
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        displayErrorMessage("Αποτυχία δημιουργίας αγωγού.", PIPE_CREATION_ERROR);
        return PIPE_CREATION_ERROR;
    }

    // Δημιουργία μιας παιδικής διεργασίας
    pid_t pid = fork();
    if (pid < 0) {
        displayErrorMessage("Αποτυχία δημιουργίας παιδικής διεργασίας.", FORK_ERROR);
        return FORK_ERROR;
    }

    if (pid == 0) {
        // Παιδική διεργασία: εκτέλεση της εντολής ταξινόμησης
        executeSortCommand(pipefd, argv[1]);
    } else {
        // Γονική διεργασία: ανάγνωση και εκτύπωση των ταξινομημένων δεδομένων
        readAndPrintSortedData(pipefd);

        // Αναμονή για την ολοκλήρωση της παιδικής διεργασίας
        int status;
        if (wait(&status) == -1) {
            displayErrorMessage("Αποτυχία αναμονής.", WAIT_ERROR);
            return WAIT_ERROR;
        }

        // Έλεγχος της κατάστασης της παιδικής διεργασίας
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0 && exit_status != 1) {
                fprintf(stderr, "Η παιδική διεργασία βγήκε με μη μηδενική κατάσταση: %d\n", exit_status);
                displayErrorMessage("Η παιδική διεργασία βγήκε με μη μηδενική κατάσταση.", CHILD_EXIT_ERROR);
                return CHILD_EXIT_ERROR;
            }
        } else {
            displayErrorMessage("Αποτυχία αναμονής.", WAIT_ERROR);
            return WAIT_ERROR;
        }
    }

    return EXIT_SUCCESS;
}

