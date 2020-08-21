#ifndef DATASTORE_HPP
#define DATASTORE_HPP

// TODO Bad to use macros
#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600

class DataStore
{
public:

   enum Data : unsigned char
   {
      DATA_COUNT
   };

   DataStore() = delete;
   DataStore(DataStore const&) = delete;
   DataStore& operator=(DataStore const&) = delete;

   static void trigger(Data);

private:


};

#endif // DATASTORE_HPP
