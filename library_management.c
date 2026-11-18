#include <stdio.h>
#include <string.h>

struct Book
{
    int id;
    char subject[20];
    char title[60];
    char content[500];
};

struct Book books[] =
{
    {1, "Mathematics", "Basic Algebra",
     "Algebra uses letters to represent unknown numbers.\n"
     "Example: x + 5 = 10, so x = 5.\n"
     "Algebra helps us solve problems with unknown values."},

    {2, "Mathematics", "Introduction to Geometry",
     "Geometry studies shapes, sizes and angles.\n"
     "A triangle has three sides and its interior angles add up to 180 degrees."},

    {3, "Physics", "Introduction to Motion",
     "Motion is a change in an object's position over time.\n"
     "Speed = Distance / Time.\n"
     "If an object travels 100 metres in 20 seconds, its speed is 5 m/s."},

    {4, "Physics", "Basic Laws of Force",
     "A force is a push or pull acting on an object.\n"
     "Newton's first law says an object remains at rest or in uniform motion\n"
     "unless an external force acts on it."},

    {5, "Chemistry", "Introduction to Atoms",
     "An atom is the basic unit of an element.\n"
     "It contains protons, neutrons and electrons.\n"
     "Protons are positive, electrons are negative and neutrons are neutral."},

    {6, "Chemistry", "Acids and Bases",
     "Acids have a pH below 7. Bases have a pH above 7.\n"
     "A neutral solution has a pH of 7.\n"
     "Litmus paper can help identify acids and bases."}
};

#define BOOK_COUNT (sizeof(books) / sizeof(books[0]))

void show_all_books(void)
{
    int i;

    printf("\n--- All Available Books ---\n");
    for (i = 0; i < BOOK_COUNT; i++)
    {
        printf("ID: %d | Subject: %s | Title: %s\n",
               books[i].id, books[i].subject, books[i].title);
    }
}

void read_book(int id)
{
    int i;

    for (i = 0; i < BOOK_COUNT; i++)
    {
        if (books[i].id == id)
        {
            printf("\n--- %s ---\n", books[i].title);
            printf("Subject: %s\n\n", books[i].subject);
            printf("%s\n", books[i].content);
            return;
        }
    }

    printf("Book not found.\n");
}

void user_menu(void)
{
    int subjectChoice, bookId, i;
    char subject[20];

    while (1)
    {
        printf("\n--- User Menu ---\n");
        printf("1. Mathematics\n");
        printf("2. Physics\n");
        printf("3. Chemistry\n");
        printf("4. Back\n");
        printf("Enter choice: ");
        if (scanf("%d", &subjectChoice) != 1)
            return;

        if (subjectChoice == 4)
            return;
        else if (subjectChoice == 1)
            strcpy(subject, "Mathematics");
        else if (subjectChoice == 2)
            strcpy(subject, "Physics");
        else if (subjectChoice == 3)
            strcpy(subject, "Chemistry");
        else
        {
            printf("Invalid choice.\n");
            continue;
        }

        printf("\nBooks in %s:\n", subject);
        for (i = 0; i < BOOK_COUNT; i++)
        {
            if (strcmp(books[i].subject, subject) == 0)
                printf("Book ID: %d - %s\n", books[i].id, books[i].title);
        }

        printf("Enter Book ID to read (0 to go back): ");
        if (scanf("%d", &bookId) != 1)
            return;

        if (bookId != 0)
        {
            int found = 0;
            for (i = 0; i < BOOK_COUNT; i++)
            {
                if (books[i].id == bookId &&
                    strcmp(books[i].subject, subject) == 0)
                    found = 1;
            }

            if (found)
                read_book(bookId);
            else
                printf("Invalid Book ID for this subject.\n");
        }
    }
}

void admin_menu(void)
{
    int choice, id;

    while (1)
    {
        printf("\n--- Admin Menu ---\n");
        printf("1. View all books\n");
        printf("2. Read any book\n");
        printf("3. Back\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            return;

        if (choice == 1)
            show_all_books();
        else if (choice == 2)
        {
            show_all_books();
            printf("Enter Book ID: ");
            if (scanf("%d", &id) != 1)
                return;
            read_book(id);
        }
        else if (choice == 3)
            return;
        else
            printf("Invalid choice.\n");
    }
}

int main(void)
{
    int choice;

    while (1)
    {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. User\n");
        printf("2. Admin\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        if (choice == 1)
            user_menu();
        else if (choice == 2)
            admin_menu();
        else if (choice == 3)
        {
            printf("Thank you!\n");
            break;
        }
        else
            printf("Invalid choice.\n");
    }

    return 0;
}
