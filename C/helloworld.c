#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//This makes text have a typing effect
    void type_text(const char *text, int delay) {
    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout);          
        Sleep(delay);  
    }
}

int main() {
    int score = 0;
    int has_key = 0;
    int made_noise = 0;
    int help_stranger = 0;
    int knows_truth = 0;
    int chose_stay = 0;
    int remained_ignorant = 0;
    char choice[50];

    type_text(
        "You just woke up from a dream, however, this is not a familiar place.\n"
        "This is not your bedroom, and more importantly, the place is empty...\n"
        "So you get out of bed, calling out to your parents--none of them replies,\n"
        "They're not here...\n"
        "You continue outside...an incomprehensibly, vast megastructure that stretches\n"
        "on the horizon. Above you is the skies, and sun, or at least thats what you think it is, \n"
        "You have no idea what this megastructure is, yet, you continue towards it.\n"
        , 100);
    type_text("You see a door on the far left, either you continue or go through that door.\n"
        ,100);

    printf("What do you do? (door/through)\n");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';   

    if (_stricmp(choice, "door") == 0) {
        type_text("You walk toward the door, curious about whats inside.\n", 100);
        score++;
        has_key = 1;
        type_text("You walk toward the door and open it. Inside, you find a small, key.\n", 100);
        type_text("You pick it up, unsure what it might unlock.\n", 80);
        type_text("You turn towards the megastructure and continue...\n", 100);
    } else if (_stricmp(choice, "through") == 0) {
        type_text("You ignore the door on the left and keep walking toward the structure.\n", 100);

    }
    type_text("The surrounding fields stretch out, colorful, yet--empty. You find no signs of life.\n"
             "You don’t know how long you are walking now, if it could have been hours, days, or even weeks \n"
             "But in the end you find a gate, it needs a key, but you could also climb it, and make a lot of noise. \n" 
        , 100);

    printf("What do you do? Climb/Key?\n");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';

    if (_stricmp(choice, "Climb") == 0) {
        type_text("You walk towards the gate--locked, with no way in you climb and jump into the other side \n"
                  "and continue forward.\n", 100);
        made_noise = 1;
    } else if (_stricmp(choice, "Key") == 0) {
        type_text("You use the key you found earlier--it works, you continue forward.\n", 100);
    }

    type_text("After so long, you find a stranger, he asks for your help.\n"
              "However, you have been walking for so long, you are not sure\n"
              "if you can trust this person at all", 100);

    type_text("Help the stranger or leave them behind? (help/leave)\n", 100); 
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';

    if (_stricmp(choice, "help") == 0) {
        type_text("The stranger thanks you, you are kind he said, and he mentioned something about a\"false sky.\"", 100);
        help_stranger = 1;
    } else if (_stricmp(choice, "leave") == 0) {
        type_text("You leave the stranger behind, you cannot trust him", 100);
    }

    type_text("Deeper in, you find yourself inside the walls of structure, you are still completely at awe \n"
              "of how massive it is...At the far end you see a glowing light, you walk towards it--curious.\n"
              "Unsure on how long it took you to get into near the glowing light, but you have arrived. \n"
              "You find a Staircase that leads underground, you hear the growling of machineries--it tantilizes you.\n"
              "However, you find another that leads you up--it sounds empty, hollow, and lifeless."
              ,100);
    
    type_text("Which staircase do you enter? The one that roars with machines and mechanisms?"
              "or the one that exude lifelessness? (Underground/Up)"
              ,100);
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';

        if (_stricmp(choice, "Underground") == 0){
    type_text("You go deeper...As with everything in this place the machines are gigantic.\n"
              "You find manuals in this room, documents, and more importantly, its history.\n"
              "You find out about this megastructure was built to house the overpopulated earth.\n"
              "Due to overdevelopment, earth lost its wildlife, aquatic habitats, and the degradation \n"
              "of the the ecosystem. The population collapsed alongside the environment, leaving the \n"
              "megastructure devoid of life."
        , 100);

    type_text("\nYou are one of the few survivors left who now knows the truth.\n"
              "Do you stay and continue the work of this place, or try to leave and find somewhere else? (stay/leave)\n"
        , 100);
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';

    if (_stricmp(choice, "stay") == 0) {
        knows_truth = 1;
        chose_stay = 1;
        score++;
        type_text("You decide to stay, taking up the burden of maintaining what's left of this place.\n", 100);
    } else if (_stricmp(choice, "leave") == 0) {
        knows_truth = 1;
        chose_stay = 0;
        type_text("You decide you cannot stay here, knowing the truth. You search for a way out.\n", 100);
    }

    } else if(_stricmp(choice, "Up") == 0){
        type_text("You choose to ignore the the roaring machineries deep underground, and continue walking up\n "
                  "and find out about the outside.", 100);

        type_text("\nYou step outside, still unaware of what this place truly is or why it was built.\n"
                  "The world outside is quiet, undisturbed. You explore it freely, questions unanswered.\n"
                    , 100);
                    remained_ignorant = 1;
}
        







    return 0;
}